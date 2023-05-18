#define _CRT_SECURE_NO_WARNINGS

/*#include <iostream>

using namespace std;

// 智能指针：
// 1、利用RAII思想设计delete资源的类
// 2、像指针一样的行为
// 3、但是存在拷贝问题
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		cout << "delete:" << _ptr << endl;
		delete _ptr;
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


//int div()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("除0错误");
//
//	return a / b;
//}
//
////void Func()
////{
////	// 1、如果p1这里new 抛异常会如何？ 
////	// 2、如果p2这里new 抛异常会如何？
////	// 3、如果div调用这里又会抛异常会如何？    都会内存泄露
////	int* p1 = new int;
////	int* p2 = new int;
////
////	cout << div() << endl;
////
////	delete p1;
////	delete p2;
////	cout << "释放资源" << endl;
////}
//
//void Func()
//{
//	// 1、如果p1这里new 抛异常会如何？ 
//	// 2、如果p2这里new 抛异常会如何？
//	// 3、如果div调用这里又会抛异常会如何？   出了作用域，或者抛异常，都会调用析构
//	SmartPtr<int> sp1(new int);
//	SmartPtr<int> sp2(new int);
//
//	*sp1 = 0;
//	*sp2 = 2;
//
//	cout << div() << endl;
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}





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

// C++98
// auto_ptr  资源管理权转移，不负责任的拷贝，会导致被拷贝对象悬空
// auto_ptr  多年以来被挂在耻辱柱上，很多公司明确要求不能使用它

// boost     // boost库是C++标准委员会成员成立的
// scoped_ptr
// shared_ptr
// weak_ptr

// C++11    // 抄boost作业
// unique_ptr 
// shared_ptr
// weak_ptr

int main()
{
	auto_ptr<A> ap1(new A);   // 库中的auto_ptr正常调用
	ap1->_a1++;
	ap1->_a2++;
	// 拷贝问题：
	auto_ptr<A> ap2(ap1);   // 相当于资源转移，ap1会变成空指针，是不负责任的拷贝
	ap1->_a1++;
	ap1->_a2++;


	SmartPtr<A> sp1(new A); // 自己实现的也正常调用
	sp1->_a1++;
	sp1->_a2++;
	// 拷贝问题：
	//SmartPtr<A> sp2(sp1);  // err 浅拷贝，指针指向同一块空间

	return 0;
}

*/



//// 智能指针
#include <iostream>
#include <string>
#include <memory>


using namespace std;

#include "SmartPtr.h"

//int main()
//{
//	// test_auto_ptr();
//	
//	// test_unique_ptr();
//	
//	// test_shared_ptr1();
//
//	// test_shared_ptr2();
//	
//	// test_shared_ptr3();
//	
//	test_shared_ptr4();
//
//	
//	return 0;
//}


//////////////////////////////////////////////////////////
// 设计一个类，只能在堆上创建对象
class HeapOnly
{
public:
	//static void Delete(HeapOnly* ptr)
	//{
	//	delete ptr;
	//}

	void Delete()
	{
		delete this;
	}

	// 提供一个公有的，获取对象的方式，对象控制是new出来的
	static HeapOnly* CreateObj()
	{
		return new HeapOnly;
	}

	// 防拷贝，禁用拷贝构造和赋值，因为默认的拷贝构造和赋值是在栈上的
	HeapOnly(const HeapOnly& hp) = delete;
	HeapOnly& operator=(const HeapOnly& hp) = delete;
private:
	// 构造函数私有化
	HeapOnly()
		:_a(0)
	{}

	// 析构函数私有化
	//~HeapOnly()
	//{
	//	std::cout << "~HeapOnly" << std::endl;
	//}
private:
	int _a;
};

//int main()
//{
//	//HeapOnly hp1;
//	//static HeapOnly hp2;
//	//
//	//HeapOnly* ptr = new HeapOnly;
//	//// HeapOnly::Delete(ptr);
//	//ptr->Delete();
//
//	HeapOnly* hp3 = HeapOnly::CreateObj();
//	hp3->Delete();
//
//	return 0;
//}

/////////////////////////////////////////////////////////
// 只能在栈上创建对象
class StackOnly
{
public:
	static StackOnly CreateObj()
	{
		StackOnly st;
		return st;
	}

	// 不能防拷贝
	//StackOnly(const StackOnly& st) = delete;
	//StackOnly& operator=(const StackOnly& st) = delete;
	
	// 防拷贝时的new
	void* operator new(size_t n) = delete;
private:
	// 构造函数私有化
	StackOnly()
		:_a(0)
	{}

private:
	int _a;
};

int main()
{
	StackOnly st1 = StackOnly::CreateObj();

	// 拷贝构造
	static StackOnly copy2(st1);  // 不好处理，算是一个小缺陷
	// StackOnly* copy3 = new StackOnly(st1);

	return 0;
}





///////////////////////////////////////////////////////////////////
// 饿汉模式 -- 一开始(main函数之前)就创建出对象
// 优点：简单、没有线程安全问题 
// 缺点：
// 1、一个程序中，多个单例，并且有先后创建初始化顺序要求时，饿汉无法控制。
// 比如程序两个单例类A 和 B，假设要求A先创建初始化，B再创建初始化。
// 2、饿汉单例类，初始化时任务多，会影响程序启动速度。

class MemoryPool
{
public:

private:
	// 构造函数私有化
	MemoryPool()
	{}

	char* _ptr = nullptr;
	// ...

	static MemoryPool _inst; // 声明
};

// 定义
MemoryPool MemoryPool::_inst;

class MemoryPool
{
public:
	static MemoryPool* GetInstance()
	{
		return _pinst;
	}

	void* Alloc(size_t n)
	{
		void* ptr = nullptr;
		// ....
		return ptr;
	}

	void Dealloc(void* ptr)
	{
		// ...
	}

private:
	// 构造函数私有化
	MemoryPool()
	{}

	char* _ptr = nullptr;
	// ...

	static MemoryPool* _pinst; // 声明
};

// 定义
MemoryPool* MemoryPool::_pinst = new MemoryPool;

/////////////////////////////////////////////////////////////////////////////////////
// 懒汉模式：第一次使用对象再创建实例对象
// 优点：
// 1、控制顺序。
// 2、不影响启动速度。

// 缺点：
// 1、相对复杂。（线程安全问题没讲）
// 2、线程安全问题要处理好
class MemoryPool
{
public:
	static MemoryPool* GetInstance()
	{
		if (_pinst == nullptr)
		{
			_pinst = new MemoryPool;
		}

		return _pinst;
	}

	void* Alloc(size_t n)
	{
		void* ptr = nullptr;
		// ....
		return ptr;
	}

	void Dealloc(void* ptr)
	{
		// ...
	}

	// 实现一个内嵌垃圾回收类    
	class CGarbo {
	public:
		~CGarbo()
		{
			if (_pinst)
				delete _pinst;
		}
	};

private:
	// 构造函数私有化
	MemoryPool()
	{
		// ....
	}

	char* _ptr = nullptr;
	// ...

	static MemoryPool* _pinst; // 声明
};

// 定义
MemoryPool* MemoryPool::_pinst = nullptr;

// 回收对象，main函数结束后，他会调用析构函数，就会释放单例对象
static MemoryPool::CGarbo gc;


// 单例对象释放问题：
// 1、一般情况下，单例对象不需要释放的。因为一般整个程序运行期间都可能会用它。
// 单例对象在进程正常结束后，也会资源释放。
// 2、有些特殊场景需要释放，比如单例对象析构时，要进行一些持久化(往文件、数据库写)操作。
// 

int main()
{
	//MemoryPool pool1;
	//MemoryPool pool2;

	void* ptr1 = MemoryPool::GetInstance()->Alloc(10);
	MemoryPool::GetInstance()->Dealloc(ptr1);
}