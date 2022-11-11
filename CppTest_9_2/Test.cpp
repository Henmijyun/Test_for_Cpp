//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//#include<string>
//#include <assert.h>
//using namespace std;

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//
//private:
//	int _a;
//};
//void Test1()
//{
//	// C
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//
//	// C++
//	int* p2 = new int;
//	// 申请5个int的数组
//	int* p3 = new int[5];
//
//	// 申请1个int对象，初始化为5
//	int* p4 = new int(5);
//
//	//C++11支持new[] 用{}初始化  C++98不支持
//	int* p5 = new int[5]{1,2,3}; // 后面默认补全为0 , 没有缺省值时可以在{}内输入的数值进行构造。	
//	// 释放
//	delete p2; 
//	delete[] p3; // new的是数组，delete也要对应加上[]
//	delete p4;
//	delete[] p5;
//
//	// 针对内置类型，new/delete跟malloc/free没有本质的区别，只有用法的区别
//	// new/delete 用法简化了
//}
//void Test2()
//{
//	// C
//	// 1、堆上申请空间
//	A* p1 = (A*)malloc(sizeof(A));
//	if (p1 == NULL)
//	{
//		perror("malloc fail");
//		exit(-1);
//	}
//	// 1、释放空间
//	free(p1);
//
//	//C++
//	// 1、堆上申请空间  2、调用构造函数初始化
//	//A* p2 = new A;
//	A* p2 = new A(10);
//
//	// 1、调用析构函数清理对象中资源 2、释放空间
//	delete p2;
//
//	cout << endl << endl;
//
//	A* p3 = new A[2];
//	delete[] p3;
// 
//	/* C++11支持
//	 A* p3 = new A[2]{1,2};
//	 A* p3 = new A[2]{ A(1), A(2) };*/
//
//	// 结论：new/delete 是为自定义类型准备的。
//	// 不仅在堆申请出来，还会调用构造和析构，进行初始化和清理。
//}
//
//void Test3()
//{
//	// C: 内存申请失败返回NULL
//	char* p1 = (char*)malloc(1024u*1024u*1024u*2 - 1);
//	//cout << p1 << endl;
//	printf("%p\n", p1);
//
//	// C++: new失败,不需要检查返回值，他失败是抛异常
//	try
//	{
//		char* p2 = new char[1024u * 1024u * 1024u * 2 - 1];
//		printf("%p\n", p2);
//		size_t n = 0;
//		/*while (1)
//		{
//		char* p2 = new char[1024]; // 重复申请空间（申请失败的例）
//		++n;
//
//		printf("%p->[%d]\n", p2, n);
//		}*/
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl; // what()函数可以知道发生了什么异常。
//	}
//}
//
//int main()
//{
//	Test1();
//	Test2();
//	Test3();
//
//	return 0;
//}
//






//// 重载operator new，在申请空间时：打印在哪个文件、哪个函数、第多少行，申请了多少个字节
//void* operator new(size_t size, const char* fileName, const char* funcName, size_t lineNo)
//{
//	void* p = ::operator new(size); // ::前面没写，说明是在全局域找。
//	cout << "new:" << fileName << "||" << funcName << "||" << lineNo << "||" << p << "||" << size << endl;
//	return p;
//}
//
//// 重载operator delete，在释放空间时：打印再那个文件、哪个函数、第多少行释放
//void operator delete(void* p, const char* fileName, const char* funcName, size_t lineNo)
//{
//	cout << "delete:" << fileName << "||" << funcName << "||" << lineNo << "||" << p << endl;
//	::operator delete(p);  // ::前面没写，说明是在全局域找。
//}
//
///*
//int main()
//{
//	// 对重载的operator new 和 operator delete进行调用
//	int* p = new(__FILE__, __FUNCTION__, __LINE__) int;
//	operator delete(p, __FILE__, __FUNCTION__, __LINE__);
//	return 0;
//}
//*/
//
// // 上述调用显然太麻烦了，可以使用宏对调用进行简化
// // 只有在Debug方式下，才调用用户重载的 operator new 和 operator delete
//#ifdef _DEBUG
//#define new new(__FILE__, __FUNCTION__, __LINE__)
////#define delete(p) operator delete(p, __FILE__, __FUNCTION__, __LINE__)
//#endif
//// 这里宏定义的delete可能无法被调用，其实可以不用宏来实现，
//// 而是直接实现一个全局的operator delete即可。
//
//int main()
//{
//	int* p1 = new int;
//	int* p2 = new int;
//
//	//delete(p); // 用宏定义 ，需要加（）
//	delete p; //不用宏，直接全局 ，不需要（）
//
//	return 0;
//}





// new -> operator new + 构造函数
// 默认情况下operator new使用全局库里面
// 每个类可以去实现自己专属operator new  new这个类对象，他就会调自己实现这个operator new

// 实现一个类专属的operator new  -- 了解一下
//struct ListNode
//{
//	int _val;
//	ListNode* _next;
//
//	// 内存池 （静态，不用重复创建）
//	static allocator<ListNode> alloc;
//
//	void* operator new(size_t n)
//	{
//		cout << "operator new -> STL内存池allocator申请" << endl;
//		void* obj = alloc.allocate(1);
//		return obj;
//	}
//
//	void operator delete(void* ptr)
//	{
//		cout << "operator delete -> STL内存池allocator申请" << endl;
//
//		alloc.deallocate((ListNode*)ptr, 1);
//	}
//
//	struct ListNode(int val)
//		:_val(val)
//		, _next(nullptr)
//	{}
//};
//
//// allocator以后会讲，现在先会用即可
//// 静态须在全局进行声明。
//allocator<ListNode> ListNode::alloc;
//
//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	// 频繁申请ListNode. 想提高效率 -- 申请ListNode时，不去malloc，而是自己定制内存池
//	ListNode* node1 = new ListNode(1);
//	ListNode* node2 = new ListNode(2);
//	ListNode* node3 = new ListNode(3);
//
//	delete node1;
//	//delete node2;
//	delete node3;
//
//	A* p1 = new A;
//
//	return 0;
//}



//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//// 定位new/replacement new
//int main()
//{
//	// p1现在指向的只不过是与A对象相同大小的一段空间，
//	// 还不能算是一个对象，因为构造函数没有执行
//	A* p1 = (A*)malloc(sizeof(A));
//	if (p1 == NULL)
//	{
//		perror("malloc fail");
//	}
//	new(p1)A; // 注意：如果A类的构造函数有参数时，此处需要传参
//
//	p1->~A();
//	free(p1);
//
//
//	A* p2 = (A*)operator new(sizeof(A));
//	if (p2 == NULL)
//	{
//		perror("malloc fail");
//	}
//	new(p2)A(10); 
//
//	p2->~A();
//	operator delete(p2);
//
//	return 0;
//}

/////////////////////////////////////////
// 模板

//泛型函数 -- 虽然利用重载和引用，但是还是需要写多个函数，很麻烦
//void Swap(int& x, int& y)
//{
//	int tmep = x;
//	x = y;
//	y = tmep;
//}
//
//void Swap(double& x, double& y)
//{
//	double tmep = x;
//	x = y;
//	y = tmep;
//}
//
//void Swap(char& x, char& y)
//{
//	char tmep = x;
//	x = y;
//	y = tmep;
//}

// 泛型编程 -- 模板
// 模板参数(模板类型) -- 类似函数参数(参数对象)
// typename后面类型名字T是随便取，Ty、K、V，一般是大写字母或者单词首字母大写
// T 代表是一个模板类型(虚拟类型)
//template<typename T>  
////template<class T>  // 也可以写class（基本相同）
//void Swap(T& left, T& right)
//{
//	T tmp = left;
//	left = right;
//	right = tmp;
//}
//
//int main()
//{
//	int i = 1, j = 2;
//	double x = 1.1, y = 2.2;
//	Swap(i, j);
//	Swap(x, y);
//
//	char m = 'A', n = 'B';
//	Swap(m, n);
//
//	//map<string, string>::iterator it = dict.begin();
//	//auto it = dict.begin(); // 与auto不同，auto主要用于编译器自动推导类型，简化代码书写
//
//	return 0;
//}
//





//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//
//private:
//	int _a;
//};
//
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//template<class T>
//T* Func(int n) // 传参只传数量，所以如果不显示写实例化，根本不知道new什么类型的对象
//{
//	T* a = new T[n]; // 生成n个T类型的数组空间，然后a指向首元素地址
//	return a;
//}
//
//int main()
//{
//	// Add(1.1, 2); // 推演实例化矛盾，报错
//
//	// 编译器自动推演，隐式实例化
//	cout << Add(1, 2) << endl;  // 自动推演类型
//
//	// 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化
//	cout << Add((int)1.1, 2) << endl;  // 1
//	cout << Add(1.1, (double)2) << endl;
//
//	// 显示实例化
//	cout << Add<int>(1.1, 2) << endl;  // 2
//	cout << Add<double>(1.1, 2) << endl; // 自己指定推演的类型，项目中不推荐不同类型混写
//
//	// 必须显示实例化才能调用
//	Func<A>(10);
//
//	return 0;
//}


//// 专门处理int的加法函数  传参类型相同时，优先度+1
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非模板函数匹配，编译器不需要特化
//	Add<int>(1, 2); // 调用编译器特化的Add版本
//}


// 专门处理int的加法函数   编译器根据传参类型，自动选择
//int Add(int left, int right)
//{
//	return left + right;
//}
//
//// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//
//void Test()
//{
//	Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
//	Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//}











//
//typedef char STDataType;
//class Stack
//{
//private:
//	STDataType* _a;
//	int top;
//	int capacity;
//};
//
//class Stacki
//{
//private:
//	int* _a;
//	int top;
//	int capacity;
//};
//
//class Stackc
//{
//private:
//	char* _a;
//	int top;
//	int capacity;
//};
//
//int main()
//{
//	Stackc st1; // char
//	Stacki st2; // int
//
//	return 0;
//}


///////////////////////////


//template<typename T>
//class Stack
//{
//public:
//	/*Stack(size_t capacity = 4)
//		:_a(nullptr)
//		, _top(0)
//		, _capacity(0)
//		{
//		if (capacity > 0)
//		{
//		_a = new T[capacity];
//		_capacity = capacity;
//		_top = 0;
//		}
//		}*/
//
//	Stack(size_t capacity = 0)
//	{
//		if (capacity > 0)
//		{
//			_a = new T[capacity];
//			_capacity = capacity;
//			_top = 0;
//		}
//	}
//
//	~Stack()
//	{
//		delete[] _a;
//		_a = nullptr;
//		_capacity = _top = 0;
//	}
//
//	void Push(const T& x);
//
//	void Pop()
//	{
//		assert(_top > 0);
//		--_top;
//	}
//
//	bool Empty()
//	{
//		return _top == 0;
//	}
//
//	const T& Top()
//	{
//		assert(_top > 0);
//
//		return _a[_top - 1];
//	}
//private:
//	T* _a = nullptr;
//	size_t _top = 0;
//	size_t _capacity = 0;
//};
//
//// 17:10继续
//template<class T>
//void Stack<T>::Push(const T& x)
//{
//	if (_top == _capacity)
//	{
//		size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
//		// 1、开新空间
//		// 2、拷贝数据
//		// 3、释放旧空间
//		T* tmp = new T[newCapacity];
//		if (_a)
//		{
//			memcpy(tmp, _a, sizeof(T)*_top);
//			delete[] _a;
//		}
//
//		_a = tmp;
//		_capacity = newCapacity;
//	}
//
//	_a[_top] = x;
//	++_top;
//}
//
//// 模板不支持分离编译。 声明放在.h  定义放在.cpp -- 原因：模板进阶再讲解
//// 模板在同一个文件中，是可以声明和定义分离的 


//#include "Stack.hpp"
//
//int main()
//{
//	try
//	{
//		// 类模板都是显示实例化
//		// 虽然他们用了一个类模板，但是Stack<int>，Stack<char> 两个类型
//		//Stack<int> st1;
//		//Stack<char> st2;
//		//Stack<Date> st3;
//
//		//// 知道自己要存100个数据，避免插入时扩容消耗
//		//Stack<int> st4(100);
//		//Stack<int> st5(0);
//
//
//		Stack<int> st1;
//		st1.Push(1);
//		st1.Push(2);
//		st1.Push(3);
//		st1.Push(4);
//		st1.Push(5);
//
//		//st1.Top()++;  // 返回值加了引用，可能会导致外部修改内部数据的情况
//		//st1.Top() *= 2;  // 所以应该在加引用 & 之后，再加上 const 防止被修改。
//
//		while (!st1.Empty())
//		{
//			cout << st1.Top() << " ";
//			st1.Pop();
//		}
//		cout << endl;
//
//		//Stack<> st2;  // 模板加了全省类型之后，创建对象的时候还是要加<>
//	}
//	catch (const exception& e) // 在工程中，try 和catch 可以让new的抛异常打印发生的异常。
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}















//// 动态顺序表
//// 注意：Vector不是具体的类，是编译器根据被实例化的类型生成具体类的模具
//template<class T>
//class Vector
//{
//public:
//	Vector(size_t capacity = 10)
//		: _pData(new T[capacity])
//		, _size(0)
//		, _capacity(capacity)
//	{}
//	// 使用析构函数演示：在类中声明，在类外定义。
//	~Vector();
//	void PushBack(const T& data)；
//		void PopBack()；
//		// ...
//		size_t Size() { return _size; }
//	T& operator[](size_t pos)
//	{
//		assert(pos < _size);
//		return _pData[pos];
//	}
//private:
//	T* _pData;
//	size_t _size;
//	size_t _capacity;
//};
//// 注意：类模板中函数放在类外进行定义时，需要加模板参数列表
//template <class T>
//Vector<T>::~Vector()
//{
//	if (_pData)
//		delete[] _pData;
//	_size = _capacity = 0;
//}




//int main()
//{
//	char a1[] = "hello";
//	char a2[] = "我草";  
//	// 通过Unicode编码系统来实现文字的表示。
//
//	//char a3[5] = { -79, -56, -52, -40, 0 }; 
//	// “比” 的编码是 -79和-56，“特” 的编码是-52和-40。
//	char a3[5] = { -50, -46, -78, -35, 0 }; 
//	cout << a3 << endl; // 我草
//
//	// 净网
//	// 国粹词库
//	// 同音字  我草 卧槽
//	
//		
//		
//		
//	/*a3[3]++;
//	cout << a3 << endl;  // 相邻的编码为同音字
//
//	a3[3]++;
//	cout << a3 << endl;
//
//	a3[3]++;
//	cout << a3 << endl;*/
//
//	a3[1]--;
//	a3[3]--;
//	cout << a3 << endl; // 窝曹
//
//	a3[1]--;
//	a3[3]--;
//	cout << a3 << endl; // 涡槽
//
//	a3[1]--;
//	a3[3]--;
//	cout << a3 << endl; // 蜗糙
//
//	char ch = 'a'; // 97
//
//	return 0;
//}







/////////////////////////////////////////////////////////
// string


//void TestString()
//{
//	string s1;
//	string s2("hello");
//}
//
//
//int main()
//{
//	TestString();
//	return 0;
//}




//多态test///////////////////////////



//
//#include <iostream>
//
//using namespace std;
//
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "Person::买票-全价" << endl;
//	}
//
//	virtual void Func1()
//	{
//		cout << "Person::Func1()" << endl;
//	}
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket()
//	{
//		cout << "Student::买票-半价" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "Student::Func2()" << endl;
//	}
//};
//
//typedef void(*VFPTR)();    // 把一个 函数指针类型 命名为 VFPTR
//
////void PrintVFTable(VFPTR table[])  // 同VFPTR* table
//// 
////void PrintVFTable(VFPTR* table, size_t n)  
//// g++环境下，不会自动在虚表末尾加nullptr，所以必须指定访问函数的个数
//
//void PrintVFTable(VFPTR* table)
//{
//	for (size_t i = 0; table[i] != nullptr; ++i)
//		//for (size_t i = 0; i < n; ++i)  // g++环境
//	{
//		printf("vft[%d]:%p->", i, table[i]);
//		//table[i]();  // 同下
//		VFPTR pf = table[i];  // 遍历每个虚表中的函数
//		pf();  // 调用该函数
//	}
//	cout << endl;
//}
//
//class Base1 {
//public:
//	virtual void func1() { cout << "Base1::func1" << endl; }
//	virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//	int b1 = 1;
//};
//
//class Base2 {
//public:
//	virtual void func1() { cout << "Base2::func1" << endl; }
//	virtual void func2() { cout << "Base2::func2" << endl; }
//private:
//	int b2 = 2;
//};
//
//class Derive : public Base1, public Base2 {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//	int d = 3;
//};
//
//int main()
//{
//	// 同一个类型的对象共用一个虚表
//	Person p1;
//	Person p2;
//
//	// vs下 不管是否完成重写，子类虚表跟父类虚表都不是同一个
//	Student s1;
//	Student s2;
//
//	/*PrintVFTable((VFPTR*)*(int*)&s1, 3);
//	PrintVFTable((VFPTR*)*(int*)&p1, 2);*/
//
//	Derive d;
//	//cout << sizeof(d) << endl;
//
//	//PrintVFTable((VFPTR*)(*(int*)&d));
//	////PrintVFTable((VFPTR*)(*(int*) ( (char*) &d+sizeof(Base1) ) ));
//
//	//Base2* ptr2 = &d;
//	//PrintVFTable((VFPTR*)(*(int*)(ptr2)));
//
//	// 符合多态，去指向对象虚函数表中去找func1的地址调用
//	Base1* ptr1 = &d;
//	ptr1->func1();
//
//	Base2* ptr2 = &d;
//	ptr2->func1();
//
//	//d.func1();
//
//	return 0;
//}


#include<iostream>
using namespace std;
class A{
public:
	A(char *s) { cout << s << endl; }
	~A(){}
};

class B :virtual public A
{
public:
	B(char *s1, char*s2) :A(s1) { cout << s2 << endl; }
};

class C :virtual public A
{
public:
	C(char *s1, char*s2) :A(s1) { cout << s2 << endl; }
};

class D :public B, public C
{
public:
	D(char *s1, char *s2, char *s3, char *s4) :B(s1, s2), C(s1, s3), A(s1)
	{
		cout << s4 << endl;
	}
};

// A：class A class B class C class D      B：class D class B class C class A

//C：class D class C class B class A      D：class A class C class B class D

int main() {
	D *p = new D("class A", "class B", "class C", "class D");
	delete p;

	//B b;
	
	return 0;
}