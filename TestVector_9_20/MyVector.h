#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <string.h>

using namespace std;


namespace skk
{
	template <class T>  // ģ��
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
			return _finish; // ���һ������+1��λ��
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

		vector(size_t n, const T& val = T()) // ��n��T���͵����ݣ����й��죬ȱʡֵΪT()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(n); // ����
			for (int i = 0; i < n; ++i)
			{
				push_back(val); // ����n��T���͵�����
			}
		}

		// v2(v1)
		/*vector(const vector<T>& v) // �������죨��ͳ�����
		{
			_start = new T[v.size()]; // v.capacity()Ҳ����
			// memcpy(_start, v._start, sizeof(T) * v.size()); // ��������
			// memcpy()������vector<vector<int>> val; ���������ֻ���������һ�㣬
			// ����һ����ǳ����������������ʱ������
			//
			for (size_t i = 0; i < v.size(); ++i)
			{
				_start[i] = v._start[i];
			}
			_finish = _start + v.size();
			_end_of_storage = _start + v.size();
		}*/

		/*vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(v.size());
			for (const auto& e : v)
			{
				push_back(e);
			}
		}*/


		template <class InputIterator>   // ģ�����Ƕ��        
		vector(InputIterator first, InputIterator last)  // ʹ�ÿ�������������ʵ�� 
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		void swap(vector<T>& v)
		{
			// ֱ�ӿ��������������ֿ�һ�����Ŀ������൱���������Ϳ���
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		// v2(v1)
		vector(const vector<T>& v) // ���α�������& ���������޵ݹ�
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}

		// v2 = v1 
		vector<T>& operator=(vector<T> v) // ����ʱ�������ֱ�Ӷ����������н������
		{
			swap(v);
			return *this;
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		size_t capacity() const  // �ռ�
		{
			return _end_of_storage - _start;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		T& operator[](size_t pos) // ���������
		{
			assert(pos < size());
			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}

		void reserve(size_t n)  // ����
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start) // ��Ϊ�վͿ���
				{
					//memcpy(tmp, _start, sizeof(T) * sz);
					// ��vector<vector<int>> val;������£��ϲ��vector�������
					// ���²��vector��ǳ���������Ի�err

					for (size_t i = 0; i < sz; ++i)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}

		void resize(size_t n, const T& val = T()) // �ı䵱ǰvector�Ĵ�СΪn
		{
			if (n > capacity())
			{

				reserve(n);
			}

			if (n > size())
			{
				// ��ʼ����ֵ
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
			else
			{
				//  ɾ������
				_finish = _start + n;
			}
		}

		void push_back(const T& x)
		{
			/*
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			++_finish;
			*/

			insert(end(), x); // ����
		}

		void pop_back()
		{
			assert(_finish > _start);
			--_finish;
		}

		iterator insert(iterator pos, const T& x) // ָ��λ�ò���
		{
			assert(pos >= _start && pos <= _finish);

			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start; // ��ֹ������ʧЧ
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}
			iterator end = _finish - 1; // ȡ���һ�����ݵ�λ��
			while (end >= pos)
			{
				*(end + 1) = *end;  //Ų������
				--end;
			}

			*pos = x;
			++_finish;

			return pos;
		}

		// STL�涨erase����ɾ��λ����һ��λ�õĵ�����
		iterator erase(iterator pos) // ָ��λ��ɾ��
		{
			assert(pos >= _start && pos < _finish);

			iterator begin = pos + 1;
			while (begin != _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}

			--_finish;

			// ���ܻ���Щ�汾�����ݵ����--��ʱ�任�ռ�
			// ����Ҳ��ʹ��ǰ������ʧЧ
			return pos;
		}

		T& front() // ����ͷλ�õ�����
		{
			assert(size() > 0);

			return *_start;
		}

		T& back()  // ����βλ�õ�����
		{
			assert(size() > 0);

			return *(_finish - 1);
		}


	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};


	void Func(const vector<int>& v)  // ֻ�ܶ������ܸ�
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

		vector<int>::iterator it = n.begin();  // ������
		while (it != n.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		n.pop_back();
		Func(n);  // constֻ����

		auto pos = find(n.begin(), n.end(), 3); // ���Ҷ�Ӧ���ݣ���ȡλ��
		if (pos != n.end())  // ����ʧ�ܵĻ�����endλ��
		{
			// ��posλ�ò��������Ժ󣬲�Ҫ����pos����Ϊpos����ʧЧ�ˡ�
			pos = n.insert(pos, 7); // ָ��λ�ò���
			++pos;
			++pos;
		}
		else
		{
			++pos;
		}

		for (auto e : n) // ��Χfor
		{
			cout << e << " ";
		}
		cout << endl;


	}

	void TestVector2()
	{
		vector<int> n;
		n.push_back(1);
		n.push_back(2);
		n.push_back(3);
		n.push_back(4);
		n.push_back(5);

		auto pos = find(n.begin(), n.end(), 1);
		if (pos != n.end())
		{
			pos = n.erase(pos); // ָ��λ��ɾ��
		}
		else
		{
			++pos;
		}

		for (auto e : n)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void TestVector3()
	{
		vector<int> n;
		n.push_back(1);
		n.push_back(2);
		n.push_back(3);
		n.push_back(4);
		n.push_back(5);
		for (auto e : n)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v(n);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void TestVector4()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		string s("hello word");
		vector<int> vs(s.begin(), s.end()); // ��s���ڴ�������й���

		for (auto e : vs)
		{
			cout << e << " ";
		}
		cout << endl;

		//vs = v; // �Ѿ����ڵ��������󣬸�ֵ����
		vector<int> copy = vs; // ����copy(v); �������� ��copy���������ڣ�

		for (auto e : copy)
		{
			cout << e << " ";
		}
		cout << endl;
	}








}













