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




	// 简化模拟shared_ptr :利用静态变量，引用计数（不可行） 
	//template<class T>
	//class shared_ptr
	//{
	//public:
	//	shared_ptr(T* ptr = nullptr)
	//		: _ptr(ptr)
	//	{
	//		++_count;
	//	}

	//	~shared_ptr()
	//	{
	//		if (--_count == 0 && _ptr)
	//		{
	//			cout << "Delete:" << _ptr << " count:" << &_count << endl;
	//			delete _ptr;
	//		}
	//	}

	//	shared_ptr(shared_ptr<T>& sp)
	//		: _ptr(sp._ptr)
	//	{
	//		++_count;
	//	}

	//	T& operator*()
	//	{
	//		return *_ptr;
	//	}

	//	T* operator->()
	//	{
	//		return _ptr;
	//	}

	//private:
	//	T* _ptr;
	//	static int _count;  // 用静态变量的方式不可行
	//};
	// 静态变量（不可行）
	//template<class T>
	//int shared_ptr<T>::_count = 0;





	// 简化模拟shared_ptr :利用指针，引用计数 
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			: _ptr(ptr)
			, _pCount(new int(1))
		{}

		// sp1(sp2)
		shared_ptr(shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pCount(sp._pCount)
		{
			(*_pCount)++;
		}

		void Release()
		{
			if (--(*_pCount) == 0)
			{
				cout << "Delete:" << _ptr << " count:" << _pCount << endl;
				delete _ptr;
				delete _pCount;
			}
		}

		~shared_ptr()
		{
			Release();
		}

		// sp1 = sp5
		// sp1 = sp1 
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			//if (this == &sp)  // err 可能有地址不相同，但是指向同一块空间
			if (sp._ptr == _ptr)
			{
				return *this;
			}

			// 减减被赋值对象的计数，如果是最后一个对象，要释放
			/*if (--(*_pCount) == 0)
			{
				cout << "Delete:" << _ptr << " count:" << _pCount << endl;
				delete _ptr;
				delete _pCount;
			}*/
			Release();

			// 共管新资源，++计数
			_ptr = sp._ptr;
			_pCount = sp._pCount;
			(*_pCount)++;

			return *this;
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
		int* _pCount;  // 每次构造时，new一个计数
		// 多线程中，可能存在隐患
	};




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
void test_shared_ptr1()
{
	skk::shared_ptr<A> sp1(new A);
	skk::shared_ptr<A> sp2(sp1);
	skk::shared_ptr<A> sp3(sp2);

	//skk::shared_ptr<int> sp4(new int);  // err 静态变量的方式
	//skk::shared_ptr<int> sp5(sp4);    // 会让 A类型的对象 和 int类型的对象 用同一个count进行计数

	skk::shared_ptr<int> sp4(new int);  // ok 指针计数
	skk::shared_ptr<A> sp5(new A);   
	skk::shared_ptr<A> sp6(sp5);

	sp1->_a1++;
	sp1->_a2++;  // 1 1
	cout << sp1->_a1 << ":" << sp1->_a2 << endl;

	sp2->_a1++;
	sp2->_a2++;   // 2 2
	cout << sp2->_a1 << ":" << sp2->_a2 << endl;

	sp1 = sp5;
	sp2 = sp5;
	sp3 = sp5;

	// 自己给自己赋值
	skk::shared_ptr<int> sp7(new int);
	sp7 = sp7;  // 减减_pCount变0，自杀了
	sp1 = sp5;  // 地址不相同，但是指向同一块空间
}


struct Node
{
	int _val;
	/*std::shared_ptr<Node> _next;
	std::shared_ptr<Node> _prev;*/

	std::weak_ptr<Node> _next;
	std::weak_ptr<Node> _prev;

	~Node()
	{
		cout << "~Node" << endl;
	}
};

// 循环引用 -- weak_ptr不是常规智能指针，没有RAII，不支持直接管理资源
// weak_ptr主要用shared_ptr构造，用来解决shared_ptr循环引用问题
void test_shared_ptr2()
{
	/*std::shared_ptr<Node> n1(new Node);
	std::shared_ptr<Node> n2(new Node);

	n1->_next = n2;
	n2->_prev = n1;*/

	std::shared_ptr<Node> n1(new Node);
	std::shared_ptr<Node> n2(new Node);

	cout << n1.use_count() << endl;
	cout << n2.use_count() << endl;

	n1->_next = n2;
	n2->_prev = n1;

	cout << n1.use_count() << endl;
	cout << n2.use_count() << endl;
}
