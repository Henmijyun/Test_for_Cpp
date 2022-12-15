#pragma once

// 闭散列 -- 向后占用别的空位
namespace CloseHash
{
	enum State
	{
		EMPTY,   // 空
		EXIST,   // 存在
		DELETE   // 删除
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};

	template<class K>
	struct HashFunc   // 仿函数 , 为了可以给不同类型取模 
	{
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};

	template<>
	struct HashFunc<string>   // 仿函数 , 特化
	{
		// BKDR哈希
		size_t operator()(const string& key)
		{
			size_t val = 0;
			for (auto ch : key)
			{
				val *= 131; //abc，acb，相加是相等的，为了区分它们,*= 131
				val += ch;
			}
			return val;
		}
	};

	//struct HashFuncString   // 仿函数 , 只针对string
	//{
	//	size_t operator()(const string& key)
	//	{
	//		size_t val = 0;
	//		for (auto ch : key)
	//		{
	//			val += ch;
	//		}
	//		return val;
	//	}
	//};



	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
			{
				return false;
			}

			// 负载因子满了就扩容
			if (_tables.size() == 0 || (10 * _size) / _tables.size() >= 7)  // 扩容  负载因子 -> 0.7
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				HashTable<K, V, Hash> newHT;
				newHT._tables.resize(newSize);  // 调整容器大小

				// 旧表的数据映射到新表
				for (auto e : _tables)
				{
					if (e._state == EXIST)
					{
						newHT.Insert(e._kv);
					}
				}
				_tables.swap(newHT._tables);   // 出了作用域，自动调用vector的析构函数
			}

			// 线性探测 -- 挨着一个一个往后占用
			Hash hash;
			size_t hashi = hash(kv.first) % _tables.size();

			while (_tables[hashi]._state == EXIST)
			{
				hashi++;
				hashi %= _tables.size();  // 走到结尾的话，再从头开始
			}

			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			++_size;


			//// 二次探测 -- 跳过一段空间后占用
			//Hash hash;
			//size_t start = hash(kv.first) % _tables.size();
			//size_t hashi = start;
			//size_t i = 0;
			//while (_tables[hashi]._state == EXIST)
			//{
			//	++i;
			//	hashi = start + i * i;  // hash + i ^ 2 (i >= 0)
			//	hashi %= _tables.size();  // 走到结尾的话，再从头开始
			//}

			//_tables[hashi]._kv = kv;
			//_tables[hashi]._state = EXIST;
			//++_size;


			return true;
		}

		HashData<K, V>* Find(const K& key)  // 查找
		{
			if (_tables.size() == 0)
			{
				return nullptr;
			}

			Hash hash;
			size_t start = hash(key) % _tables.size();
			size_t hashi = start;
			while (_tables[hashi]._state != EMPTY)  // 不等于空
			{
				if (_tables[hashi]._state != DELETE
					&& _tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}
				++hashi;
				hashi %= _tables.size();

				if (hashi == start)  // 全部是DELETE删除的情况
				{
					break;
				}
			}

			return nullptr;
		}

		bool Erase(const K& key)  // 删除
		{
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				--_size;
				return true;
			}
			else
			{
				return false;
			}
		}

		void Print()
		{
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				if (_tables[i]._state == EXIST)
				{
					printf("[%d:%d] ", i, _tables[i]._kv.first);
				}
				else
				{
					printf("[%d:*] ", i);
				}
			}
			cout << endl;
		}
	private:
		//vector<pair<K, V>> _tables;
		vector<HashData<K, V>> _tables;
		size_t _size = 0;   // 存储多少个有效数据
	};

	void TestHash1()
	{
		int a[] = { 1, 11, 4, 15, 26, 7, 44 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}
		ht.Print();

		ht.Erase(4);
		cout << ht.Find(44)->_kv.first << endl;
		cout << ht.Find(4) << endl;
		ht.Print();

		ht.Insert(make_pair(-2, -2)); // 负数在查找比较的时候，整型提升为无符号数，再取模
		ht.Print();
	}

	void TestHash2()
	{
		string arr[] = { "apple", "banana", "watermelon", "watermelon", "banana",  "banana" };

		//HashTable<string, int, HashFuncString> countHT; // 统计次数
		HashTable<string, int> countHT;
		for (auto& str : arr)
		{
			auto ptr = countHT.Find(str);
			if (ptr)
			{
				ptr->_kv.second++;
			}
			else
			{
				countHT.Insert(make_pair(str, 1));
			}
		}
		countHT.Print();
	}

	void TestHash3()
	{
		HashFunc<string> hash;
		cout << hash("abcd") << endl;
		cout << hash("bcad") << endl;
		cout << hash("eat") << endl;
		cout << hash("tae") << endl;
		cout << hash("aadd") << endl;
		cout << hash("abcd") << endl << endl;

		cout << hash("abcd") << endl;
		cout << hash("bcad") << endl;
		cout << hash("eat") << endl;
		cout << hash("tae") << endl;
		cout << hash("aadd") << endl;
		cout << hash("abcd") << endl << endl;
	}
}

// 开散列 -- 拉链法、哈希桶
namespace HashBucket
{
	template<class K, class V>
	struct HashNode
	{
		pair<K, V> _kv;
		HashNode<K, V>* _next;

		HashNode(const pair<K, V>& kv)
			:_kv(kv)
			,_next(nullptr)
		{}
	};
	
	template<class K, class V>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
		~HashTable()
		{
			// 释放桶空间
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					free(cur);
					cur = next;
				}
				_tables[i] = nullptr;
			}
		}

		bool Insert(const pair<K, V>& kv)
		{
			// 去重
			if (Find(kv.first))
			{
				return false;
			}

			// 负载因子到1就扩容
			if (_size == _tables.size())
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node*> newTables;
				newTables.resize(newSize, nullptr); // 调整容器大小
				
				// 旧表中节点移动映射新表
				for (size_t i = 0; i < _tables.size(); ++i)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;

						size_t hashi = cur->_kv.first % newTables.size();
						cur->_next = newTables[hashi];
						newTables[hashi] = cur;

						cur = next;
					}

					_tables[i] = nullptr;
				}

				_tables.swap(newTables);
			}

			size_t hashi = kv.first % _tables.size();
			// 头插
			Node* newnode = new Node(kv);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_size;

			return true;
		}

		Node* Find(const K& key)
		{
			if (_tables.size() == 0)
			{
				return nullptr;
			}

			size_t hashi = key % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}
				cur = cur->_next;
			}

			return nullptr;
		}
	private:
		vector<Node*> _tables;
		size_t _size = 0;  // 存储的有效数据个数
	};

	void TestHash1()
	{
		int a[] = { 1, 11, 4, 15, 26, 7, 44, 25, 77, 35 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		ht.Insert(make_pair(22, 22));
	}
}