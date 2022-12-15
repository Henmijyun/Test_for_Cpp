#pragma once

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

template<class K, class V>
class HashTable
{
public:
	bool Insert(const pair<K, V>& kv)
	{
		// 负载因子满了就扩容
		if (_tables.size() == 0 || (10 * _size) / _tables.size() >= 7)  // 扩容  负载因子 -> 0.7
		{
			size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
			HashTable<K, V> newHT;
			newHT._tables.resize(newSize);  // 调整容器大小

			// 旧表的数据映射到新表
			for (auto e : _tables)
			{
				if (e._state == EXIST)
				{
					newHT.Insert(e._kv);
				}
			}
			_tables.swap()
		}
		size_t hashi = kv.first % _tables.size();
		size_t i = 0;
		// 线性探测
		while (_tables[hashi]._state == EXIST)
		{
			hashi++;
			hashi %= _tables.size();  // 走到结尾的话，再从头开始
		}

		_tables[hashi]._kv = kv;
		_tables[hashi]._state = EXIST;
		++_size;
	}

private:
	//vector<pair<K, V>> _tables;
	vector<HashData<K, V>> _tables;
	size_t _size = 0;   // 存储多少个有效数据
};