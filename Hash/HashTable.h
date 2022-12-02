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
		if (_table.size() == 0 || (10 * _size) / _table.size() >= 7)  // 扩容 0.7
		{

		}
		size_t hashi = kv.first % _table.size();
		size_t i = 0;
		// 线性探测
		while (_table[hashi]._state == EXIST)
		{
			hashi++;
			hashi %= _table.size();  // 走到结尾的话，再从头开始
		}

		_table[hashi]._kv = kv;
		_table[hashi]._state = EXIST;
		++_size;
	}

private:
	//vector<pair<K, V>> _table;
	vector<HashData<K, V>> _table;
	size_t _size = 0;   // 存储多少个有效数据
};