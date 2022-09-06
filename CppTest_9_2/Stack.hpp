#pragma once


// .hpp文件：.h文件中有模板的声明和实现。

//template<typename T = char> // 模板也可以加缺省值，但是加的是类型
template<typename T>
class Stack
{
public:
	// 构造函数两种写法：1、初始化列表  2、声明+缺省值
	/*Stack(size_t capacity = 4)  // 写法1（推荐）
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

	const T& Top() // 加引用 & 之后，再加上 const 防止被修改。
	{
		assert(_top > 0);

		return _a[_top - 1];
	}
private:
	T* _a = nullptr;   // 写法2（不太推荐）
	size_t _top = 0;
	size_t _capacity = 0;
};

template<class T>
void Stack<T>::Push(const T& x)  // 在类外定义时，不仅指定类域，还要指定模板参数
{
	if (_top == _capacity)
	{
		size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
		// 1、开新空间
		// 2、拷贝数据
		// 3、释放旧空间
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

// 模板不支持分离编译。 声明放在.h  定义放在.cpp -- 原因：模板进阶再讲解
// 模板在同一个文件中，是可以声明和定义分离的
// #include "Stack.hpp"
