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
		// �����������˾�����
		if (_tables.size() == 0 || (10 * _size) / _tables.size() >= 7)  // ����  �������� -> 0.7
		{
			size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
			HashTable<K, V> newHT;
			newHT._tables.resize(newSize);  // ����������С

			// �ɱ������ӳ�䵽�±�
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
		// ����̽��
		while (_tables[hashi]._state == EXIST)
		{
			hashi++;
			hashi %= _tables.size();  // �ߵ���β�Ļ����ٴ�ͷ��ʼ
		}

		_tables[hashi]._kv = kv;
		_tables[hashi]._state = EXIST;
		++_size;
	}

private:
	//vector<pair<K, V>> _tables;
	vector<HashData<K, V>> _tables;
	size_t _size = 0;   // �洢���ٸ���Ч����
};