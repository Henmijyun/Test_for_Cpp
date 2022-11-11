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
//	// ����5��int������
//	int* p3 = new int[5];
//
//	// ����1��int���󣬳�ʼ��Ϊ5
//	int* p4 = new int(5);
//
//	//C++11֧��new[] ��{}��ʼ��  C++98��֧��
//	int* p5 = new int[5]{1,2,3}; // ����Ĭ�ϲ�ȫΪ0 , û��ȱʡֵʱ������{}���������ֵ���й��졣	
//	// �ͷ�
//	delete p2; 
//	delete[] p3; // new�������飬deleteҲҪ��Ӧ����[]
//	delete p4;
//	delete[] p5;
//
//	// ����������ͣ�new/delete��malloc/freeû�б��ʵ�����ֻ���÷�������
//	// new/delete �÷�����
//}
//void Test2()
//{
//	// C
//	// 1����������ռ�
//	A* p1 = (A*)malloc(sizeof(A));
//	if (p1 == NULL)
//	{
//		perror("malloc fail");
//		exit(-1);
//	}
//	// 1���ͷſռ�
//	free(p1);
//
//	//C++
//	// 1����������ռ�  2�����ù��캯����ʼ��
//	//A* p2 = new A;
//	A* p2 = new A(10);
//
//	// 1�������������������������Դ 2���ͷſռ�
//	delete p2;
//
//	cout << endl << endl;
//
//	A* p3 = new A[2];
//	delete[] p3;
// 
//	/* C++11֧��
//	 A* p3 = new A[2]{1,2};
//	 A* p3 = new A[2]{ A(1), A(2) };*/
//
//	// ���ۣ�new/delete ��Ϊ�Զ�������׼���ġ�
//	// �����ڶ����������������ù�������������г�ʼ��������
//}
//
//void Test3()
//{
//	// C: �ڴ�����ʧ�ܷ���NULL
//	char* p1 = (char*)malloc(1024u*1024u*1024u*2 - 1);
//	//cout << p1 << endl;
//	printf("%p\n", p1);
//
//	// C++: newʧ��,����Ҫ��鷵��ֵ����ʧ�������쳣
//	try
//	{
//		char* p2 = new char[1024u * 1024u * 1024u * 2 - 1];
//		printf("%p\n", p2);
//		size_t n = 0;
//		/*while (1)
//		{
//		char* p2 = new char[1024]; // �ظ�����ռ䣨����ʧ�ܵ�����
//		++n;
//
//		printf("%p->[%d]\n", p2, n);
//		}*/
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl; // what()��������֪��������ʲô�쳣��
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






//// ����operator new��������ռ�ʱ����ӡ���ĸ��ļ����ĸ��������ڶ����У������˶��ٸ��ֽ�
//void* operator new(size_t size, const char* fileName, const char* funcName, size_t lineNo)
//{
//	void* p = ::operator new(size); // ::ǰ��ûд��˵������ȫ�����ҡ�
//	cout << "new:" << fileName << "||" << funcName << "||" << lineNo << "||" << p << "||" << size << endl;
//	return p;
//}
//
//// ����operator delete�����ͷſռ�ʱ����ӡ���Ǹ��ļ����ĸ��������ڶ������ͷ�
//void operator delete(void* p, const char* fileName, const char* funcName, size_t lineNo)
//{
//	cout << "delete:" << fileName << "||" << funcName << "||" << lineNo << "||" << p << endl;
//	::operator delete(p);  // ::ǰ��ûд��˵������ȫ�����ҡ�
//}
//
///*
//int main()
//{
//	// �����ص�operator new �� operator delete���е���
//	int* p = new(__FILE__, __FUNCTION__, __LINE__) int;
//	operator delete(p, __FILE__, __FUNCTION__, __LINE__);
//	return 0;
//}
//*/
//
// // ����������Ȼ̫�鷳�ˣ�����ʹ�ú�Ե��ý��м�
// // ֻ����Debug��ʽ�£��ŵ����û����ص� operator new �� operator delete
//#ifdef _DEBUG
//#define new new(__FILE__, __FUNCTION__, __LINE__)
////#define delete(p) operator delete(p, __FILE__, __FUNCTION__, __LINE__)
//#endif
//// ����궨���delete�����޷������ã���ʵ���Բ��ú���ʵ�֣�
//// ����ֱ��ʵ��һ��ȫ�ֵ�operator delete���ɡ�
//
//int main()
//{
//	int* p1 = new int;
//	int* p2 = new int;
//
//	//delete(p); // �ú궨�� ����Ҫ�ӣ���
//	delete p; //���úֱ꣬��ȫ�� ������Ҫ����
//
//	return 0;
//}





// new -> operator new + ���캯��
// Ĭ�������operator newʹ��ȫ�ֿ�����
// ÿ�������ȥʵ���Լ�ר��operator new  new�����������ͻ���Լ�ʵ�����operator new

// ʵ��һ����ר����operator new  -- �˽�һ��
//struct ListNode
//{
//	int _val;
//	ListNode* _next;
//
//	// �ڴ�� ����̬�������ظ�������
//	static allocator<ListNode> alloc;
//
//	void* operator new(size_t n)
//	{
//		cout << "operator new -> STL�ڴ��allocator����" << endl;
//		void* obj = alloc.allocate(1);
//		return obj;
//	}
//
//	void operator delete(void* ptr)
//	{
//		cout << "operator delete -> STL�ڴ��allocator����" << endl;
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
//// allocator�Ժ�ὲ�������Ȼ��ü���
//// ��̬����ȫ�ֽ���������
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
//	// Ƶ������ListNode. �����Ч�� -- ����ListNodeʱ����ȥmalloc�������Լ������ڴ��
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
//// ��λnew/replacement new
//int main()
//{
//	// p1����ָ���ֻ��������A������ͬ��С��һ�οռ䣬
//	// ����������һ��������Ϊ���캯��û��ִ��
//	A* p1 = (A*)malloc(sizeof(A));
//	if (p1 == NULL)
//	{
//		perror("malloc fail");
//	}
//	new(p1)A; // ע�⣺���A��Ĺ��캯���в���ʱ���˴���Ҫ����
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
// ģ��

//���ͺ��� -- ��Ȼ�������غ����ã����ǻ�����Ҫд������������鷳
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

// ���ͱ�� -- ģ��
// ģ�����(ģ������) -- ���ƺ�������(��������)
// typename������������T�����ȡ��Ty��K��V��һ���Ǵ�д��ĸ���ߵ�������ĸ��д
// T ������һ��ģ������(��������)
//template<typename T>  
////template<class T>  // Ҳ����дclass��������ͬ��
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
//	//auto it = dict.begin(); // ��auto��ͬ��auto��Ҫ���ڱ������Զ��Ƶ����ͣ��򻯴�����д
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
//T* Func(int n) // ����ֻ�������������������ʾдʵ������������֪��newʲô���͵Ķ���
//{
//	T* a = new T[n]; // ����n��T���͵�����ռ䣬Ȼ��aָ����Ԫ�ص�ַ
//	return a;
//}
//
//int main()
//{
//	// Add(1.1, 2); // ����ʵ����ì�ܣ�����
//
//	// �������Զ����ݣ���ʽʵ����
//	cout << Add(1, 2) << endl;  // �Զ���������
//
//	// ��ʱ�����ִ���ʽ��1. �û��Լ���ǿ��ת�� 2. ʹ����ʽʵ����
//	cout << Add((int)1.1, 2) << endl;  // 1
//	cout << Add(1.1, (double)2) << endl;
//
//	// ��ʾʵ����
//	cout << Add<int>(1.1, 2) << endl;  // 2
//	cout << Add<double>(1.1, 2) << endl; // �Լ�ָ�����ݵ����ͣ���Ŀ�в��Ƽ���ͬ���ͻ�д
//
//	// ������ʾʵ�������ܵ���
//	Func<A>(10);
//
//	return 0;
//}


//// ר�Ŵ���int�ļӷ�����  ����������ͬʱ�����ȶ�+1
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
//	Add<int>(1, 2); // ���ñ������ػ���Add�汾
//}


// ר�Ŵ���int�ļӷ�����   ���������ݴ������ͣ��Զ�ѡ��
//int Add(int left, int right)
//{
//	return left + right;
//}
//
//// ͨ�üӷ�����
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//
//void Test()
//{
//	Add(1, 2); // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//	Add(1, 2.0); // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
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
//// 17:10����
//template<class T>
//void Stack<T>::Push(const T& x)
//{
//	if (_top == _capacity)
//	{
//		size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
//		// 1�����¿ռ�
//		// 2����������
//		// 3���ͷžɿռ�
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
//// ģ�岻֧�ַ�����롣 ��������.h  �������.cpp -- ԭ��ģ������ٽ���
//// ģ����ͬһ���ļ��У��ǿ��������Ͷ������� 


//#include "Stack.hpp"
//
//int main()
//{
//	try
//	{
//		// ��ģ�嶼����ʾʵ����
//		// ��Ȼ��������һ����ģ�壬����Stack<int>��Stack<char> ��������
//		//Stack<int> st1;
//		//Stack<char> st2;
//		//Stack<Date> st3;
//
//		//// ֪���Լ�Ҫ��100�����ݣ��������ʱ��������
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
//		//st1.Top()++;  // ����ֵ�������ã����ܻᵼ���ⲿ�޸��ڲ����ݵ����
//		//st1.Top() *= 2;  // ����Ӧ���ڼ����� & ֮���ټ��� const ��ֹ���޸ġ�
//
//		while (!st1.Empty())
//		{
//			cout << st1.Top() << " ";
//			st1.Pop();
//		}
//		cout << endl;
//
//		//Stack<> st2;  // ģ�����ȫʡ����֮�󣬴��������ʱ����Ҫ��<>
//	}
//	catch (const exception& e) // �ڹ����У�try ��catch ������new�����쳣��ӡ�������쳣��
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}















//// ��̬˳���
//// ע�⣺Vector���Ǿ�����࣬�Ǳ��������ݱ�ʵ�������������ɾ������ģ��
//template<class T>
//class Vector
//{
//public:
//	Vector(size_t capacity = 10)
//		: _pData(new T[capacity])
//		, _size(0)
//		, _capacity(capacity)
//	{}
//	// ʹ������������ʾ�������������������ⶨ�塣
//	~Vector();
//	void PushBack(const T& data)��
//		void PopBack()��
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
//// ע�⣺��ģ���к�������������ж���ʱ����Ҫ��ģ������б�
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
//	char a2[] = "�Ҳ�";  
//	// ͨ��Unicode����ϵͳ��ʵ�����ֵı�ʾ��
//
//	//char a3[5] = { -79, -56, -52, -40, 0 }; 
//	// ���ȡ� �ı����� -79��-56�����ء� �ı�����-52��-40��
//	char a3[5] = { -50, -46, -78, -35, 0 }; 
//	cout << a3 << endl; // �Ҳ�
//
//	// ����
//	// ����ʿ�
//	// ͬ����  �Ҳ� �Բ�
//	
//		
//		
//		
//	/*a3[3]++;
//	cout << a3 << endl;  // ���ڵı���Ϊͬ����
//
//	a3[3]++;
//	cout << a3 << endl;
//
//	a3[3]++;
//	cout << a3 << endl;*/
//
//	a3[1]--;
//	a3[3]--;
//	cout << a3 << endl; // �Ѳ�
//
//	a3[1]--;
//	a3[3]--;
//	cout << a3 << endl; // �в�
//
//	a3[1]--;
//	a3[3]--;
//	cout << a3 << endl; // �ϲ�
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




//��̬test///////////////////////////



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
//		cout << "Person::��Ʊ-ȫ��" << endl;
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
//		cout << "Student::��Ʊ-���" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "Student::Func2()" << endl;
//	}
//};
//
//typedef void(*VFPTR)();    // ��һ�� ����ָ������ ����Ϊ VFPTR
//
////void PrintVFTable(VFPTR table[])  // ͬVFPTR* table
//// 
////void PrintVFTable(VFPTR* table, size_t n)  
//// g++�����£������Զ������ĩβ��nullptr�����Ա���ָ�����ʺ����ĸ���
//
//void PrintVFTable(VFPTR* table)
//{
//	for (size_t i = 0; table[i] != nullptr; ++i)
//		//for (size_t i = 0; i < n; ++i)  // g++����
//	{
//		printf("vft[%d]:%p->", i, table[i]);
//		//table[i]();  // ͬ��
//		VFPTR pf = table[i];  // ����ÿ������еĺ���
//		pf();  // ���øú���
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
//	// ͬһ�����͵Ķ�����һ�����
//	Person p1;
//	Person p2;
//
//	// vs�� �����Ƿ������д���������������������ͬһ��
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
//	// ���϶�̬��ȥָ������麯������ȥ��func1�ĵ�ַ����
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

// A��class A class B class C class D      B��class D class B class C class A

//C��class D class C class B class A      D��class A class C class B class D

int main() {
	D *p = new D("class A", "class B", "class C", "class D");
	delete p;

	//B b;
	
	return 0;
}