

//#include <iostream>
//using namespace std;
//inline������������������������£��ڵ��õĵط�չ��
//inline int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	cout << Add(1, 2) << endl;
//
//	return 0;
//}
//
//
//#include <iostream>
//using namespace std;
//
//int TestAuto()
//{
//	return 10;
//}
//int main()
//{
//
//
//	int a = 10;
//	auto b = &a;  //int*
//	auto* c = &a;  //int* ǿ��һ��Ҫ��ָ��
//	auto& e = a;    //int ǿ��c��һ������
//
//
//	auto d = TestAuto();  //���ݺ�������ֵ���Զ��Ƶ� ����d ������
//
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(e).name() << endl;
//	
//	//auto e; �޷�ͨ�����룬ʹ��auto�������ʱ���������г�ʼ��
//
//	return 0;
//}

//
//#include <iostream>
//using namespace std;
//int main()
//{
//	int a[] = { 1,2,3,4,5,6 };
//	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
//	{
//		cout << a[i] << endl;
//	}
//	cout << endl;
//
//	��Χfor
//	�Զ�����ȡa�����ݣ���ֵ��e
//	�Զ��������Զ��жϽ���
//	for (auto e : a)
//	{
//		cout << e << endl;
//	}
//	cout << endl;
//
//	for (auto& e : a)
//	{
//		e--;
//	}
//	return 0;
//}
//

//
//#include <iostream>
//using namespace std;

//void TestFor(int array[])
//{
//	for (auto& e : array)
//		cout << e << endl;
//}
//
//
//int main()
//{
//	int a[] = { 1,2,3,4,5,6 };
//
//	for (auto& e : a)
//	{
//		e--;
//	}
//	return 0;
//}

//
//void f(int)
//{
//	cout << "f(int)" << endl;
//}
//void f(int*)
//{
//	cout << "f(int*)" << endl;
//}
//int main()
//{
//	int* p = NULL;
//	f(0);
//	f(NULL);
//	f(p);
//
//	// C++11 nullptr
//	f(nullptr);
//	int* ptr = nullptr;
//
//	return 0;
//}



//// C
//typedef struct ListNode_C
//{
//	struct ListNode_C* next; 
//	int val;
//}LTNode;
//
//// C++
//struct ListNode_CPP
//{
//	ListNode_CPP* next; //���ﶨ�岻��дstruct����Ϊ��������
//	int val;
//};

// C:
//struct Stack
//{
//	int* a;
//	int top;
//	int capacity;
//};
//void StackInit(struct Stack* ps);
//void StackPush(struct Stack* ps, int x);
//void StackPop(struct Stack* ps);

//C++����C struct�﷨
// ͬʱ��struct �������� �ࡣ
// 
//����Զ��壺
// ��Ա����
// ��Ա������������
//struct Stack
//{
//	int* a;
//	int top;
//	int capacity;
//
//	void Init()  //��Ϊ�����������棬��������������ͻ����
//	{
//		a = 0;
//		top = capacity = 0;
//	}
//
//	void Push(int x)
//	{
//		//...
//	}
//
//	void Pop()
//	{
//		//..
//	}
//};
//
//int main()
//{
//	struct Stack st1;  //C���ԵĶ��巽ʽ�����ݣ�
//	Stack st2;  //C++�Ķ��巽ʽ
//
//	st1.Init();
//	st1.Push(1);
//	st1.Push(2);
//	st1.Push(3);
//
//	return 0;
//}

//
//class Stack
//{
////ֱ����һ�������޶���Ϊֹ������˽�У�����������β
////������ĳ�Ա���Է��ʣ�������ĺ������Է��ʣ����������ԣ�
//private:
//	int* a;
//	int top;
//	int capacity;
//	
////ֱ����һ�������޶���Ϊֹ�����ǹ��У�����������β
//public:
//	void Init()  //��Ϊ�����������棬��������������ͻ����
//	{
//		a = 0;
//		top = capacity = 0;
//	}
//
//	void Push(int x)
//	{
//		//...
//	}
//
//	void Pop()
//	{
//		//..
//	}
//
//};
//
//int main()
//{
//	struct Stack st1;  //C���ԵĶ��巽ʽ�����ݣ�
//	Stack st2;  //C++�Ķ��巽ʽ
//
//	st1.Init();
//	st1.Push(1);
//	st1.Push(2);
//	st1.Push(3);
//
//	return 0;
//}




//#include "Person.h"
//
//// ���н��г�Ա����
//class A2
//{
//public:
//	void f2() {}
//};
//
//// ����ʲô��û�� -- ����
//class A3
//{
//};
//
//int main()
//{
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3) << endl;
//	
//	//û�г�Ա����������󣬸�1byte��ռλ�����洢ʵ�����ݣ���ʶ�������
//	A2 aa2;
//	A2 aaa2;
//	cout << &aa2 << endl;
//	cout << &aaa2 << endl;
//
//	A3 aa3;
//
//
//
//
//
//	//cout << "static size_1:" << &size_1 << endl;
//	//cout << "age:" << &age << endl;
//
//	//cout << sizeof(Person) << endl;
//
//	//Person p1; //���ʵ����
//	//Person p2;
//	//Person p3;
//
//	//p1.PrintPersonInfo();
//
//	return 0;
//}




// ���ʺ͵���֮������ĸ��д��� -- �շ巨 GetYear
// ����ȫ��Сд������֮��_�ָ�           get_year
// ���ã��շ巨
// a�������������������е�������ĸ��д   DateMgr
// b����������ĸСд�����浥������ĸ��д  dateMgr
// c����Ա�������׵���ǰ���_           _deteMgr 

//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//
//	void Print()
//	{
//		cout << this->_year << "-" << 
//			this->_month << "-" << this->_day << endl;
//	}
//
//private:
//	int _year;   //��  -> ����
//	int _month;  //��
//	int _day;    //��
//};
//
//int main()
//{
//	Date d1;
//	d1.Init(2022, 8, 24);
//
//	Date d2;
//	d2.Init(2022, 8, 25);
//
//	d1.Print();
//	d2.Print();
//
//	//Date d1;
//	//d1.Init(&d1, 2022, 8, 24);
//
//	//Date d2;
//	//d2.Init(&d2, 2022, 8, 25);
//
//	//d1.Print(&d1);
//	//d2.Print(&d2);
//
//	return 0;
//}
//
//
//class A
//{
//public:
//	void print()
//	{
//		cout << this << endl;  //д��д�������������
//		cout << "Print()" << endl; //ֱ�Ӵ�ӡ������Ҫ������
//	}
//	void printA()
//	{
//		cout << this << endl;  // this���ָ��
//		cout << _a << endl;   // ������this���������б���
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//	p->print(); // ��������
//
//	p->printA(); // ���б���  �����ÿ�ָ��
//
//	return 0;
//}




#include "Person.h"

class Date
{
public:
	//void Init(int year, int month, int day)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
// ����Init�����ù��캯��
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
// ���캯�����Ժ������� ������ �޲��� �� ȫȱʡ �������ظ����塣
 
	//Date() 
	//{
	//	_year = 1;
	//	_month = 1;
	//	_day = 1;
	//}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;   
	int _month;  
	int _day;    
};

typedef int DataType;
class Stack
{
public:
	//void Init(size_t capacity = 3)
	//{
	//	_array = (DataType*)malloc(sizeof(DataType) * capacity);
	//	if (NULL == _array)
	//	{
	//		perror("malloc����ռ�ʧ��!!!");
	//		return;
	//	}
	//	_capacity = capacity;
	//	_size = 0;
	//}
// ���캯��
	Stack(size_t capacity = 4)
	{
		_array = (DataType*)malloc(sizeof(DataType) * capacity);
		if (NULL == _array)
		{
			perror("malloc����ռ�ʧ��!!!");
			return;
		}
		_capacity = capacity;
		_size = 0;
	}

	void Push(DataType data)
	{
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}


private:
	DataType* _array;
	int _capacity;
	int _size;
};

// ����Init��ʼ�������ܻ����ǣ����±����������ֵ��
// �ܲ��ܱ�֤����һ������ʼ���� -- ���캯��
int main()
{
	//Date d1;
	//d1.Init(2022, 8, 24);

	Date d1(2022, 8, 24);
	Date d2;

	Stack st;

	return 0;
}


