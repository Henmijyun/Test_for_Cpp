

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




//#include "Person.h"
//
//class Date
//{
//public:
//	//void Init(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//// ����Init�����ù��캯��
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//// ���캯�����Ժ������� ������ �޲��� �� ȫȱʡ �������ظ����塣
// 
//	//Date() 
//	//{
//	//	_year = 1;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year = 1;  // ע�����ﲻ�ǳ�ʼ�����Ǹ�ȱʡֵ��Ĭ�Ϲ��캯����   
//	int _month = 1;  // ��Ϊ����������
//	int _day = 1;    
//};
//
//typedef int DataType;
//class Stack
//{
//public:
//	//void Init(size_t capacity = 3)
//	//{
//	//	_array = (DataType*)malloc(sizeof(DataType) * capacity);
//	//	if (NULL == _array)
//	//	{
//	//		perror("malloc����ռ�ʧ��!!!");
//	//		return;
//	//	}
//	//	_capacity = capacity;
//	//	_size = 0;
//	//}
//// ���캯��
//	Stack(size_t capacity = 4)
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc����ռ�ʧ��!!!");
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//
//private:
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//
//class MyQueue
//{
//private:
//	Stack _st1;
//	Stack _st2;
//};
//
//
//// ����Init��ʼ�������ܻ����ǣ����±����������ֵ��
//// �ܲ��ܱ�֤����һ������ʼ���� -- ���캯��
//int main()
//{
//	//Date d1;
//	//d1.Init(2022, 8, 24);
//
//	//Date d1(2022, 8, 24);
//	//Date d2;
//
//	//Stack st;
//	//st.Push(9);
//	//st.Push(0);
//
//// Ĭ�����ɹ��캯����
//// a���������ͳ�Ա��������
//// b���Զ������ͳ�Ա��ȥ��������Ĭ�Ϲ��캯��
//// ��������C++������Ƶ�һ��ȱ�ݣ�
//// Ĭ�����ɹ��캯��������Ӧ����������Ҳһ������������ֻ�����Զ������͡�
//// C++11 ����һ������
//
//	Date d;
//
//	MyQueue q;
//
//	return 0;
//}
//
//

//
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 3) // ȫȱʡ���캯��
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc����ռ�ʧ��!!!");
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	~Stack() // �������� ~����
//	{
//		if (_array)
//		{
//			cout << "~Stack():" << _array << endl;
//			//�����ӡ��Ϊ����֤����ϵͳ�Զ���������������
//
//			free(_array);  //����Ҫ�ͷſռ�ʱ��
//			_array = NULL;  //һ��Ҫд������������Դй©
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//  ��ʽ�Զ����������� ����ʵ�ֲ�ͬ�ռ��ͷš�(�Լ�д)
//  Queue
//  List   ��ʽ�ṹ��ѭ������ڵ��ͷţ�
//  SeqList  ˳��ṹ���ͷ�����ͷ��ַ��
//  BinaryTree  ���ṹ���ݹ��ͷţ�
//private:
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//void TestStack()
//{
//	Stack s;
//	s.Push(1);
//	s.Push(2);  //����д�ӡ��˵������ϵͳ�Զ���������������
//}
// 
//int main()
//{
//	TestStack();
//	return 0;
//}

//#include "Person.h"
//
//class Time
//{
//public:
//	~Time() // ��������
//	{
//		cout << "~Time()" << endl;
//		// ��ӡΪ����֤�Ƿ��е���
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	// ��������(��������)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//
//	// �Զ�������
//	Time _t;  
//
//	// ���Ա������ʱ�����������ɵ�Ĭ������������
//	// ���Զ����ͳ�Ա������������������
//};
//int main()
//{
//	Date d;  // �����ӡ��
//	return 0;
//}


//
//
//
//#include "Person.h"
//
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 3) // ȫȱʡ���캯��
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc����ռ�ʧ��!!!");
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	~Stack() // ��������
//	{
//		if (_array)
//		{
//			free(_array); 
//			_array = NULL; 
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//
//private:
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d) // ��������ʵ�ֿ������캯��
//	{
//		//��const ��ֹ��ֵ����
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//private:
//	int _year;   
//	int _month;  
//	int _day;    
//};
//void TestStack()
//{
//	Date d1(2022, 7, 23);
//	Date d2(d1);
//}
// 
//int main()
//{
//	TestStack();
//	return 0;
//}


//���������/////////////////
//#include "Person.h"
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	bool operator==(const Date& x) //���صĲ���this
//	{
//		return _year == x._year
//			&& _month == x._month
//			&& _day == x._day;
//	}
//private:
//	int _year;   
//	int _month;
//	int _day;    
//};
////bool operator==(const Date& x1, const Date& x2) //������ó�Ա��˽�еģ��������޷�����
////{
////	return x1._year == x2._year
////		&& x1._month == x2._month
////		&& x1._day == x2._day;
////}
//
//int main()
//{
//	Date d1(2022, 7, 23);
//	Date d2(2022, 7, 25);
//
//	//�������Ϳ���ֱ��ʹ����������㣬������֪��������㡣
//	//�Զ��������޷�ֱ��ʹ���������������Ҳ��֪��������㡣��֧�֣���Ҫ�Լ�ʵ����������ء�
//	//��ȫ�����壺
//	//cout << (d1 == d2) << endl; 
//	//cout << operator==(d1, d2) << endl; //���������Զ�ת����ʶ��
//
//	//�����ж��壺
//	cout << (d1 == d2) << endl;
//	cout << d1.operator==(d2) << endl;
//
//
//	return 0;
//}


/////////////////////////////////////////////////////////////////
//������
//#include "Date.h"
//
//
//void TestDate1()
//{
//	Date d1(2022, 8, 29);
//	Date d2(d1);
//
//	Date d3(2022, 9, 10);
//	d2 = d1 = d3; 	// d1.operator=(&d1, d3)
//}
//
//void TestDate2()
//{
//	Date d4(2022, 8, 25);
//	Date d5(2022, 8, 1);
//	Date d6(2022, 2, 20);
//	//d4 += 4;
//	//d4.Print();
//
//	//d4 += 40;
//	//d4.Print(); // ����
//
//	//d4 += 400;
//	//d4.Print(); // ����
//
//	//d4 += 4000;
//	//d4.Print(); // ������
//
//	(d4 + 4).Print(); // ���÷���ֵ��ӡ
//	(d4 + 40).Print(); // ����
//	(d4 + 400).Print(); // ����
//	(d4 + 4000).Print(); // ������
//
//	(d4++).Print();
//	(++d4).Print();
//	
//	cout << (d5 - d4) << endl;
//}
//
//void TestDate3()
//{
//	int i = 0;
//	double d = 1.1;
//	Date d6(2022, 6, 8);
//	cout << i << endl; // cout.operator<<(i); ��ĵײ��õ��ǣ����������+��������
//	cout << d << endl; // cout.operator<<(d);
//	cout << d6; // �Լ�д����ȫ��������Ԫ���������������<< 
//}
//
//void TestMenu()
//{
//	const char* WeeDayToStr[] = { "��һ","�ܶ�","����","����","����","����","����" };
//	Date d1,d2;
//	int day = 0;
//	int option = 0;
//	do
//	{
//		cout << "*******************************" << endl;
//		cout << " 1�����ڼ�/������ 2�����ڼ�����" << endl;
//		cout << " 3������->�ܼ�   -1���˳�" << endl;
//		cout << "*******************************" << endl;
//		
//		cout << "������:>";
//		cin >> option;
//		if (option == 1)
//		{
//			cout << "�������������ں������������������븺����:";
//			cin >> d1 >> day;  // �� IO�豸 ��ȡ�� ����ͱ���
//			cout << "���ڼӼ�����������ڣ�" << d1 + day << endl;
//		}
//		else if (option == 2)
//		{
//			cout << "������������������:>";
//			cin >> d1 >> d2;  // �� IO�豸 ��ȡ�� ����ͱ���
//			cout << "����������" << d2 - d1 << endl;
//		}
//		else if (option == 3)
//		{
//			cout << "����������:>";
//			cin >> d1;
//			Date start(1, 1, 1); // ��ԪԪ��
//			int n = d1 - start; // ��������
//			int weekDay = 0;  // ��һ  �պö�Ӧ�����±�
//			weekDay += n;
//			//cout << "��" << weekDay % 7 + 1 << endl;
//			cout << WeeDayToStr[weekDay % 7]<< endl;
//
//		}
//		else
//		{ 
//			if (option != -1)
//			{
//				cout << "�޴�ѡ�������ѡ��" << endl;
//			}
//		}
//	} while (option != -1);
//}
//
//void TestDate4()
//{
//	Date d1(2022, 8, 25);
//	const Date d2(2022, 8, 25);
//	d1.Print();
//	d2.Print();
//
//	d1 < d2;
//	d2 < d1;
//
//}
//
//int main()
//{
//	//TestDate1();
//	//TestDate2();
//	//TestDate3();
//	TestMenu();
//	TestDate4();
//	return 0;
//}








////////////////////////////////////////////////////////////
//��ʼ���б�

//class A
//{
//public:
//	A(int)
//	{}
//private:
//	int _a;
//};
//
//class B
//{
//public:
//	B(int a, int x)  
//		:_aobj(a)
//		, _ref(x)
//		, _n(10)
//	{
//		_ref++; //x��y����ʱ������������int& x �Ż�Ӱ�������y
//	}
//private:
//	A _aobj; // û��Ĭ�Ϲ��캯��
//	int& _ref; // ����
//	const int _n; // const
//	int _year = 0; 
//	// C++11���� ȱʡֵ -- ��ʼ���б��ڳ�ʼ��ʱû����ʾд���ͻ������ȱʡֵ
//};
//int main()
//{
//	int y = 0;
//	B num(50, y);
//
//	return 0;
//}
//

//
//#include <iostream>
//using namespace std;
//
//class Date
//{
//public:
//	//explicit���ι��캯������ֹ����ת��
//	//explicit Date(int year)
//	Date(int year)
//		:_year(year)
//	{
//		cout << "Date(int year)" << endl;
//	}
//
//	Date(const Date& d)
//	{
//		//��������
//	}
//private:
//	int _year;
//};
//
//int main()
//{
//	Date d1(2022);  // ֱ�ӵ��ù���
//	Date d2 = 2022; // ��ʽ����ת�������� + �������� + �Ż� ����> ֱ�ӵ��ù���
//	const Date& d3 = 2022;
//
//	int i = 10;
//	const double& d = i;
//	
//
//	return 0;
//}
//




//
//class Date
//{
//public:
//	// 1. ���ι��캯����û��ʹ��explicit���Σ���������ת������
//	// explicit���ι��캯������ֹ����ת��---explicitȥ��֮�󣬴������ͨ������
//	explicit Date(int year)
//		:_year(year)
//	{}
//	
//	// 2. ��Ȼ�ж�����������Ǵ�������ʱ�������������Բ����ݣ�û��ʹ��explicit���Σ���������ת������
//	// explicit���ι��캯������ֹ����ת��
//	//explicit Date(int year, int month = 1, int day = 1)
//	//: _year(year)
//	//, _month(month)
//	//, _day(day)
//	//{}
//	
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void Test()
//{
//	Date d1(2022);
//	// ��һ�����α������������Ͷ���ֵ
//	// ʵ�ʱ������������2023����һ������������������������d1������и�ֵ
//	d1 = 2023;
//
//	// ��1���ε���2�ſ�ʱ�����ʧ�ܣ���Ϊexplicit���ι��캯������ֹ�˵��ι��캯������ת��������
//}
//











/////////////////////////////////////////////////////////////
// ��̬��Ա����
// 
//class A
//{
//public:
//	A() 
//	{ ++_scount; }
//
//	A(const A& t) { ++_scount; }
//
//	// ��̬��Ա���� --  û��thisָ��
//	static int GetCount()
//	{
//		//_a = 1; //err ֻ�ܷ��ʾ�̬��Ա
//
//		return _scount;
//	}
//
//private:
//	int _a;
//	// ��̬��Ա���������������࣬���������������������ڼ䣬���ھ�̬ȡ
//	static int _scount;  // ����  ����ھ�̬��
//};
//
//// �����涨���ʼ��
//int A::_scount = 0;
//
////int main()
////{
////	A a1;
////	A a2;
////	A a3(a2);
////
////	//cout << a1._scount << endl;
////	//cout << a2._scount << endl;
////	//cout << A::_scount << endl;
////
////	cout <<A::GetCount() << endl;
////
////	return 0;
////}
//
//// ���һ��ֻ����ջ�϶���������
//class StackOnly
//{
//public:
//	static StackOnly CreateObj() // ��̬��Ա����û��thisָ�룬����Ҫ����Ҳ���Ե���
//	{
//		StackOnly so;
//		return so;
//	}
//
//private:
//	StackOnly(int x = 0, int y = 0)
//		:_x(x)
//		, _y(0)
//	{}
//private:
//	int _x = 0;
//	int _y = 0;
//};
//
//int main()
//{
//	//StackOnly so1; // ջ
//	//static StackOnly so2; // ��̬��
//
//	StackOnly so3 = StackOnly::CreateObj(); 
//	// ���þ�̬��Ա���������ԣ�ʵ��һ��ֻ����ջ�϶���������
//
//	return 0;
//}




// ������ << ��������� ȫ�� ����Ԫ��
// ��Ϊcout�����в�������Ϊ�����������������̶�Ϊthis�����Զ�����ȫ���С�
// ȫ�����޷��������е�˽�г�Ա��������Ҫ����Ԫ������ʵ�ַ���˽�С�
// ȫ������ + ��Ԫ������ʵ�֣� cout << d1;
// ������ֵ�� cout << d1 << d2; ����ʹ��
//class Date
//{
//	//��Ԫ����������
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, Date& d);
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//// ��Ԫ�����Ķ���
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//istream& operator>>(istream& _cin, Date& d)
//{
//	_cin >> d._year;
//	_cin >> d._month;
//	_cin >> d._day;
//	return _cin;
//}
//int main()
//{
//	Date d;
//	cin >> d;
//	cout << d << endl;
//	return 0;
//}


#include <iostream>
using namespace std;
//class Time
//{
//	friend class Date; // ����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time���е�˽�г�Ա����
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// ֱ�ӷ���ʱ����˽�еĳ�Ա����
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};



///////////////////////////////////////////////////////////////////////////////////////////
// �ڲ���
//class A
//{
//private:
//	int _h;
//	static int k;
//public:
//	// B������A������
//	//  1����A�� ���� �� �����޶��� �����ơ�
//	//  2��B������A����Ԫ�� 
//	class B
//	{
//	public:
//		void foo1(const A& a)
//		{
//			cout << k << endl;//OK
//			cout << a._h << endl;//OK -- ��Ԫ
//		}
//	private:
//		int _b;
//	};
//
//	void foo2(const B& a)
//	{
//		cout << a._b << endl; //err
//		// ��Ԫ�ǵ���ģ�B->A OK , A->B err
//	}
//};
//int A::k = 1;
//
//int main()
//{
//	cout << sizeof(A) << endl; // 4
//	A a;
//	A::B b;
//
//	return 0;
//}


class W
{
public:
	W(int x = 0) //����
	{
		cout << "W()" << endl;
	}

	W(const W& w) //��������
	{
		cout << "W(const W& w)" << endl;
	}

	W& operator=(const W& w) //��ֵ���������
	{
		cout << "W& operator=(const W& w)" << endl;
		return *this;
	}

	~W() //����
	{
		cout << "~W()" << endl;
	}
};
//
//void f1(W w)
//{}
//
//void f2(const W& w)
//{}
//
//int main()
//{
//	W w1;
//	f1(w1);
//	f2(w1);
//	cout << endl << endl;
//
//	f1(W()); // ��������+��������--���������Ż�--ֱ�ӹ���
//	// ���ۣ�����һ�����ʽ�����У���������һ�㶼���Ż� -- �϶�Ϊһ
//
//	W w2 = 1;
//
//	return 0;
//}

//W f3()
//{
//	W ret;
//	return ret;
//}
//
// //�����̽��C++����ģ�͡�
//int main()
//{
//	f3(); 
//	// 1�ι���  1�ο���
//	cout << endl << endl;
//
//	W w1 = f3(); 
//	// ������1�ι���  2�ο��� -- �Ż���1�ι���  1�ο���
//
//	cout << endl << endl;
//
//	W w2;
//	w2 = f3(); 
//	// ������1�ι���  1�ο��� 1�θ�ֵ  
//	// ����һ�����ʽ���裬���Բ��Ż�
//
//	return 0;
//}

W f(W u)
{
	cout << "--------" << endl;
	W v(u);
	W w = v;
	cout << "--------" << endl;
	return w;
}

int main()
{
	W x;
	W y = f(f(x)); // 1�ι���  7�ο���  or  1�ι���  5�ο���

	return 0;
}

//int main()
//{
//	W x;
//	W y = f(x); // 1�ι���  4�ο���
//
//	return 0;
//}
//






