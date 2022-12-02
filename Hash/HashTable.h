#pragma once

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

template<class K, class V>
class HashTable
{
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_table.size() == 0 || (10 * _size) / _table.size() >= 7)  // ���� 0.7
		{

		}
		size_t hashi = kv.first % _table.size();
		size_t i = 0;
		// ����̽��
		while (_table[hashi]._state == EXIST)
		{
			hashi++;
			hashi %= _table.size();  // �ߵ���β�Ļ����ٴ�ͷ��ʼ
		}

		_table[hashi]._kv = kv;
		_table[hashi]._state = EXIST;
		++_size;
	}

private:
	//vector<pair<K, V>> _table;
	vector<HashData<K, V>> _table;
	size_t _size = 0;   // �洢���ٸ���Ч����
};