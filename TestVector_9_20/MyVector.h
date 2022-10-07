#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;


namespace skk
{
	template <class T>  // ģ��
	class vector
	{
		typedef T* iterator;
	public:
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}

		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		size_t capacity()const  // �ռ�
 		{
			return _end_of_storage - _start;
		}

		size_t size()const
		{
			return _finish - _start;
		}

		T& operator[](size_t pos)  // ���������
		{
			assert(pos < size());
			return _start[pos];
		}

		void reserve(size_t n)
		{
			if (n > capacity)
			{
				T* tmp = new T[n];
				if (_start) // ��Ϊ�վͿ���
				{
					memcpy(tmp, _start, sizeof(T) * size());
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + size();
				_end_of_storage = _start + n;
			}
		}


	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

	void TestVector1()
	{

	}
}