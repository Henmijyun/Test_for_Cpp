#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;


namespace skk
{
	template <class T>  // 模板
	class vector
	{
		
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}

		const_iterator begin() const
		{
			return _start;
		}
		
		iterator end()
		{
			return _finish; // 最后一个数据+1的位置
		}

		const_iterator end() const
		{
			return _finish; 
		}


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

		size_t capacity() const  // 空间
 		{
			return _end_of_storage - _start;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		T& operator[](size_t pos) // 运算符重载
		{
			assert(pos < size());
			return _start[pos];
		}

		const T& operator[](size_t pos) const 
		{
			assert(pos < size());
			return _start[pos];
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start) // 不为空就拷贝
				{
					memcpy(tmp, _start, sizeof(T) * sz);
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}

		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			++_finish;
		}

		void pop_back()
		{
			assert(_finish > _start);
			--_finish;
		}

		void insert(iterator pos, const T& x) // 指定位置插入
		{
			assert(pos >= _start && pos <= _finish);
			
			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start; // 防止迭代器失效
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}
			iterator end = _finish - 1; // 取最后一个数据的位置
			while (end >= pos)
			{
				*(end + 1) = *end;  //挪动数据
				--end;
			}

			*pos = x;
			++_finish;
		}

		void erase(iterator pos) // 指定位置删除
		{

		}


	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};


	void Func(const vector<int>& v)  // 只能读，不能改
	{
		vector<int>::const_iterator it = v.begin();
		while (it != v.end()) 
		{
			cout << *it << " ";  
			++it;
		}
		cout << endl;
	}

	void TestVector1()
	{
		vector<int> n;
		n.push_back(1);
		n.push_back(2);
		n.push_back(3);
		n.push_back(4);
		n.push_back(5);

		vector<int>::iterator it = n.begin();  // 迭代器
		while (it != n.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		n.pop_back();
		Func(n);  // const只读版

		auto pos = find(n.begin(), n.end(), 3); // 查找对应数据，获取位置
		if (pos != n.end())  // 查找失败的话返回end位置
		{
			n.insert(pos, 7); // 指定位置插入
		}
		for (auto e : n) // 范围for
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void TestVector2()
	{

	}

}