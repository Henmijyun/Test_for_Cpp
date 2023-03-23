#pragma once
class A
{
public:
	~A()
	{
		cout << "~A()" << endl;
	}
	//private:
	int _a1 = 0;
	int _a2 = 0;
};

// 1、RAII
// 2、像指针一样
// 3、拷贝问题 -- > 很多解决方案
template<class T>
class SmartPtr {
public:
	SmartPtr(T* ptr = nullptr)
		: _ptr(ptr)
	{}

	~SmartPtr()
	{
		if (_ptr)
		{
			cout << "Delete:" << _ptr << endl;
			delete _ptr;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

private:
	T* _ptr;
};


namespace skk
{
	// 模拟实现auto_ptr  管理权转移，反面教材
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr = nullptr)
			: _ptr(ptr)
		{}

		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;  // 把指针拿了过来，再置空，相当于交换
		}

		// ap1 = ap2
		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr)
				{
					cout << "Delete:" << _ptr << endl;
					delete _ptr;
				}

				// 管理权转移
				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}
			return *this;
		}

		~auto_ptr()
		{
			if (_ptr)
			{
				cout << "Delete:" << _ptr << endl;
				delete _ptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};


	// 模拟实现unique_ptr :不让拷贝
	template<class T>
	class unique_ptr 
	{
	private:
		// 防拷贝C++98
		// 只声明不实现，并设置为私有，防止外部实现
		// unique_ptr(unique_ptr<T>& ap);
		// unique_ptr<T>& operator=(unique_ptr<T>& ap);
	public:
		unique_ptr(T* ptr = nullptr)
			: _ptr(ptr)
		{}

		// 不写拷贝，编译器会自动生成
		// 不想让编译器生成默认拷贝函数 delete  防拷贝
		unique_ptr(unique_ptr<T>& ap) = delete;

		// 防拷贝
		unique_ptr<T>& operator=(unique_ptr<T>& ap) = delete;


		// 防拷贝C++11
		/* unique_ptr(unique_ptr<T>& ap) = delete;
		   unique_ptr<T>& operator=(unique_ptr<T>& ap) = delete;
		 */


		~unique_ptr()
		{
			if (_ptr)
			{
				cout << "Delete:" << _ptr << endl;
				delete _ptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};


	// 简化模拟shared_ptr :利用引用计数
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			: _ptr(ptr)
		{}

		shared_ptr(shared_ptr<T>& sp)
			:_ptr(sp._ptr)
		{
			++_count;   // 每次计数++
		}

		// ap1 = ap2
		shared_ptr<T>& operator=(shared_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr)
				{
					cout << "Delete:" << _ptr << endl;
					delete _ptr;
				}

				// 管理权转移
				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}
			return *this;
		}

		~shared_ptr()
		{
			if (--_count == 0 && _ptr)
			{
				cout << "Delete:" << _ptr << endl;
				delete _ptr;
			}
		}



		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;

		static int _count;  // 引用计数
	};
	// 静态变量
	template<class T>
	int shared_ptr<T>::_count = 0;

}

// boost -- 探路者
// scoped_ptr / shared_ptr / weak_ptr

// C++11 -- 抄boost库的作业
// unique_ptr / shared_ptr / weak_ptr



// C++98 auto_ptr 管理权转移，被拷贝对象会出现悬空问题
// 很多公司明确的要求不能使用它
void test_auto_ptr()
{
	skk::auto_ptr<A> ap1(new A);
	ap1->_a1++;
	ap1->_a2++;

	skk::auto_ptr<A> ap2(ap1);
	ap2->_a1++;
	ap2->_a2++;

	// ap1->_a1++;  // err ap1的资源转移到了ap2
	// ap1->_a2++;  // err ap1悬空

	skk::auto_ptr<A> ap3(new A);
	ap2 = ap3;

	ap2->_a1++;  // 1 1
	ap2->_a2++;

	cout << ap2->_a1 << "  " << ap2->_a2 << endl;
}

// unique_ptr :简单粗暴，直接不让拷贝
void test_unique_ptr()
{
	skk::unique_ptr<A> up1(new A);
	// skk::unique_ptr<A> up2(up1);    // err 
	up1->_a1++;
	up1->_a2++;
}

// shared_ptr :利用引用计数
void test_shared_ptr()
{
	skk::shared_ptr<A> sp1(new A);
	skk::shared_ptr<A> sp2(sp1);
	skk::shared_ptr<A> sp3(sp2);

	sp1->_a1++;
	sp1->_a2++;  // 1 1
	cout << sp1->_a1 << ":" << sp1->_a2 << endl;

	sp2->_a1++;
	sp2->_a2++;   // 2 2
	cout << sp2->_a1 << ":" << sp2->_a2 << endl;
}