#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <iostream>
using namespace std;

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
template<typename T>  
//template<class T>  // 也可以写class（基本相同）
void Swap(T& left, T& right)
{
	T tmp = left;
	left = right;
	right = tmp;
}

int main()
{
	int i = 1, j = 2;
	double x = 1.1, y = 2.2;
	Swap(i, j);
	Swap(x, y);

	char m = 'A', n = 'B';
	Swap(m, n);

	//map<string, string>::iterator it = dict.begin();
	//auto it = dict.begin(); // 与auto不同，auto主要用于编译器自动推导类型，简化代码书写

	return 0;
}

