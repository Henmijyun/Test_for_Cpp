#pragma once


// .hpp�ļ���.h�ļ�����ģ���������ʵ�֡�

//template<typename T = char> // ģ��Ҳ���Լ�ȱʡֵ�����Ǽӵ�������
template<typename T>
class Stack
{
public:
	// ���캯������д����1����ʼ���б�  2������+ȱʡֵ
	/*Stack(size_t capacity = 4)  // д��1���Ƽ���
		:_a(nullptr)
		, _top(0)
		, _capacity(0)
		{
		if (capacity > 0)
		{
		_a = new T[capacity];
		_capacity = capacity;
		_top = 0;
		}
		}*/

	Stack(size_t capacity = 0)
	{
		if (capacity > 0)
		{
			_a = new T[capacity];
			_capacity = capacity;
			_top = 0;
		}
	}

	~Stack()
	{
		delete[] _a;
		_a = nullptr;
		_capacity = _top = 0;
	}

	void Push(const T& x);

	void Pop()
	{
		assert(_top > 0);
		--_top;
	}

	bool Empty()
	{
		return _top == 0;
	}

	const T& Top() // ������ & ֮���ټ��� const ��ֹ���޸ġ�
	{
		assert(_top > 0);

		return _a[_top - 1];
	}
private:
	T* _a = nullptr;   // д��2����̫�Ƽ���
	size_t _top = 0;
	size_t _capacity = 0;
};

template<class T>
void Stack<T>::Push(const T& x)  // �����ⶨ��ʱ������ָ�����򣬻�Ҫָ��ģ�����
{
	if (_top == _capacity)
	{
		size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
		// 1�����¿ռ�
		// 2����������
		// 3���ͷžɿռ�
		T* tmp = new T[newCapacity];
		if (_a)
		{
			memcpy(tmp, _a, sizeof(T) * _top);
			delete[] _a;
		}

		_a = tmp;
		_capacity = newCapacity;
	}

	_a[_top] = x;
	++_top;
}

// ģ�岻֧�ַ�����롣 ��������.h  �������.cpp -- ԭ��ģ������ٽ���
// ģ����ͬһ���ļ��У��ǿ��������Ͷ�������
// #include "Stack.hpp"
