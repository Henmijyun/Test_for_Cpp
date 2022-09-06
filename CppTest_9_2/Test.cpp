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
template<typename T>  
//template<class T>  // Ҳ����дclass��������ͬ��
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
	//auto it = dict.begin(); // ��auto��ͬ��auto��Ҫ���ڱ������Զ��Ƶ����ͣ��򻯴�����д

	return 0;
}

