#pragma once

// ��ɢ�� -- ���ռ�ñ�Ŀ�λ
namespace CloseHash
{
	enum State
	{
		EMPTY,   // ��
		EXIST,   // ����
		DELETE   // ɾ��
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};

	template<class K>
	struct HashFunc   // �º��� , Ϊ�˿��Ը���ͬ����ȡģ 
	{
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};

	template<>
	struct HashFunc<string>   // �º��� , �ػ�
	{
		// BKDR��ϣ
		size_t operator()(const string& key)
		{
			size_t val = 0;
			for (auto ch : key)
			{
				val *= 131; //abc��acb���������ȵģ�Ϊ����������,*= 131
				val += ch;
			}
			return val;
		}
	};

	//struct HashFuncString   // �º��� , ֻ���string
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

			// �����������˾�����
			if (_tables.size() == 0 || (10 * _size) / _tables.size() >= 7)  // ����  �������� -> 0.7
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				HashTable<K, V, Hash> newHT;
				newHT._tables.resize(newSize);  // ����������С

				// �ɱ������ӳ�䵽�±�
				for (auto e : _tables)
				{
					if (e._state == EXIST)
					{
						newHT.Insert(e._kv);
					}
				}
				_tables.swap(newHT._tables);   // �����������Զ�����vector����������
			}

			// ����̽�� -- ����һ��һ������ռ��
			Hash hash;
			size_t hashi = hash(kv.first) % _tables.size();

			while (_tables[hashi]._state == EXIST)
			{
				hashi++;
				hashi %= _tables.size();  // �ߵ���β�Ļ����ٴ�ͷ��ʼ
			}

			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			++_size;


			//// ����̽�� -- ����һ�οռ��ռ��
			//Hash hash;
			//size_t start = hash(kv.first) % _tables.size();
			//size_t hashi = start;
			//size_t i = 0;
			//while (_tables[hashi]._state == EXIST)
			//{
			//	++i;
			//	hashi = start + i * i;  // hash + i ^ 2 (i >= 0)
			//	hashi %= _tables.size();  // �ߵ���β�Ļ����ٴ�ͷ��ʼ
			//}

			//_tables[hashi]._kv = kv;
			//_tables[hashi]._state = EXIST;
			//++_size;


			return true;
		}

		HashData<K, V>* Find(const K& key)  // ����
		{
			if (_tables.size() == 0)
			{
				return nullptr;
			}

			Hash hash;
			size_t start = hash(key) % _tables.size();
			size_t hashi = start;
			while (_tables[hashi]._state != EMPTY)  // �����ڿ�
			{
				if (_tables[hashi]._state != DELETE
					&& _tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}
				++hashi;
				hashi %= _tables.size();

				if (hashi == start)  // ȫ����DELETEɾ�������
				{
					break;
				}
			}

			return nullptr;
		}

		bool Erase(const K& key)  // ɾ��
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
		size_t _size = 0;   // �洢���ٸ���Ч����
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

		ht.Insert(make_pair(-2, -2)); // �����ڲ��ұȽϵ�ʱ����������Ϊ�޷���������ȡģ
		ht.Print();
	}

	void TestHash2()
	{
		string arr[] = { "apple", "banana", "watermelon", "watermelon", "banana",  "banana" };

		//HashTable<string, int, HashFuncString> countHT; // ͳ�ƴ���
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

// ��ɢ�� -- ����������ϣͰ
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
			// �ͷ�Ͱ�ռ�
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
			// ȥ��
			if (Find(kv.first))
			{
				return false;
			}

			// �������ӵ�1������
			if (_size == _tables.size())
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node*> newTables;
				newTables.resize(newSize, nullptr); // ����������С
				
				// �ɱ��нڵ��ƶ�ӳ���±�
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
			// ͷ��
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
		size_t _size = 0;  // �洢����Ч���ݸ���
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