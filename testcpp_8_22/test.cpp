

//#include <iostream>
//using namespace std;
//inline内联函数：符合条件的情况下，在调用的地方展开
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
//	auto* c = &a;  //int* 强调一定要传指针
//	auto& e = a;    //int 强调c是一个引用
//
//
//	auto d = TestAuto();  //根据函数返回值，自动推导 变量d 的类型
//
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(e).name() << endl;
//	
//	//auto e; 无法通过编译，使用auto定义变量时必须对其进行初始化
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
//	范围for
//	自动依次取a的数据，赋值给e
//	自动迭代，自动判断结束
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
//	ListNode_CPP* next; //这里定义不用写struct，因为这里是类
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

//C++兼容C struct语法
// 同时将struct 升级成了 类。
// 
//类可以定义：
// 成员变量
// 成员函数（方法）
//struct Stack
//{
//	int* a;
//	int top;
//	int capacity;
//
//	void Init()  //因为定义在类里面，不用在意命名冲突问题
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
//	struct Stack st1;  //C语言的定义方式（兼容）
//	Stack st2;  //C++的定义方式
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
////直到下一个访问限定符为止，都是私有，除非遇到结尾
////类里面的成员可以访问（类里面的函数可以访问，其他不可以）
//private:
//	int* a;
//	int top;
//	int capacity;
//	
////直到下一个访问限定符为止，都是公有，除非遇到结尾
//public:
//	void Init()  //因为定义在类里面，不用在意命名冲突问题
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
//	struct Stack st1;  //C语言的定义方式（兼容）
//	Stack st2;  //C++的定义方式
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
//// 类中仅有成员函数
//class A2
//{
//public:
//	void f2() {}
//};
//
//// 类中什么都没有 -- 空类
//class A3
//{
//};
//
//int main()
//{
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3) << endl;
//	
//	//没有成员变量的类对象，给1byte，占位，不存储实际数据，标识对象存在
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
//	//Person p1; //类的实例化
//	//Person p2;
//	//Person p3;
//
//	//p1.PrintPersonInfo();
//
//	return 0;
//}




// 单词和单词之间首字母大写间隔 -- 驼峰法 GetYear
// 单词全部小写，单词之间_分割           get_year
// 课堂：驼峰法
// a、函数名、类名等所有单词首字母大写   DateMgr
// b、变量首字母小写，后面单词首字母大写  dateMgr
// c、成员变量，首单词前面加_           _deteMgr 

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
//	int _year;   //年  -> 声明
//	int _month;  //月
//	int _day;    //日
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
//		cout << this << endl;  //写不写，编译器都会加
//		cout << "Print()" << endl; //直接打印，不需要解引用
//	}
//	void printA()
//	{
//		cout << this << endl;  // this变空指针
//		cout << _a << endl;   // 解引用this，所以运行崩溃
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//	p->print(); // 正常运行
//
//	p->printA(); // 运行崩溃  解引用空指针
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
//// 不用Init，改用构造函数
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//// 构造函数可以函数重载 ，但是 无参数 和 全缺省 不可以重复定义。
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
//	int _year = 1;  // 注意这里不是初始化，是给缺省值（默认构造函数）   
//	int _month = 1;  // 因为这里是声明
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
//	//		perror("malloc申请空间失败!!!");
//	//		return;
//	//	}
//	//	_capacity = capacity;
//	//	_size = 0;
//	//}
//// 构造函数
//	Stack(size_t capacity = 4)
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc申请空间失败!!!");
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
//// 调用Init初始化，可能会忘记！导致崩溃出现随机值。
//// 能不能保证对象一定被初始化？ -- 构造函数
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
//// 默认生成构造函数，
//// a：内置类型成员不做处理。
//// b：自定义类型成员会去调用他的默认构造函数
//// 这个设计是C++早期设计的一个缺陷，
//// 默认生成构造函数，本来应该内置类型也一并处理，但现在只处理自定义类型。
//// C++11 打了一个补丁
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
//	Stack(size_t capacity = 3) // 全缺省构造函数
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc申请空间失败!!!");
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
//	~Stack() // 析构函数 ~类名
//	{
//		if (_array)
//		{
//			cout << "~Stack():" << _array << endl;
//			//这里打印是为了验证编译系统自动调用了析构函数
//
//			free(_array);  //有需要释放空间时，
//			_array = NULL;  //一定要写，否则会造成资源泄漏
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//  显式自定义析构函数 可以实现不同空间释放。(自己写)
//  Queue
//  List   链式结构（循环逐个节点释放）
//  SeqList  顺序结构（释放数组头地址）
//  BinaryTree  树结构（递归释放）
//private:
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//void TestStack()
//{
//	Stack s;
//	s.Push(1);
//	s.Push(2);  //结果有打印，说明编译系统自动调用了析构函数
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
//	~Time() // 析构函数
//	{
//		cout << "~Time()" << endl;
//		// 打印为了验证是否有调用
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	// 基本类型(内置类型)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//
//	// 自定义类型
//	Time _t;  
//
//	// 类成员的销毁时，编译器生成的默认析构函数，
//	// 对自定类型成员调用它的析构函数。
//};
//int main()
//{
//	Date d;  // 结果打印了
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
//	Stack(size_t capacity = 3) // 全缺省构造函数
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc申请空间失败!!!");
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
//	~Stack() // 析构函数
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
//	Date(const Date& d) // 用引用来实现拷贝构造函数
//	{
//		//加const 防止赋值出错
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


//运算符重载/////////////////
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
//	bool operator==(const Date& x) //隐藏的参数this
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
////bool operator==(const Date& x1, const Date& x2) //类的内置成员是私有的，在外面无法访问
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
//	//内置类型可以直接使用运算符运算，编译器知道如何运算。
//	//自定义类型无法直接使用运算符，编译器也不知道如何运算。想支持，需要自己实现运算符重载。
//	//在全局域定义：
//	//cout << (d1 == d2) << endl; 
//	//cout << operator==(d1, d2) << endl; //编译器会自动转换和识别
//
//	//在类中定义：
//	cout << (d1 == d2) << endl;
//	cout << d1.operator==(d2) << endl;
//
//
//	return 0;
//}



#include "Date.h"


void TestDate1()
{
	Date d1(2022, 8, 29);
	Date d2(d1);

	Date d3(2022, 9, 10);
	d2 = d1 = d3; 	// d1.operator=(&d1, d3)
}

void TestDate2()
{
	Date d4(2022, 8, 25);
	Date d5(2022, 8, 1);
	Date d6(2022, 2, 20);
	//d4 += 4;
	//d4.Print();

	//d4 += 40;
	//d4.Print(); // 跨月

	//d4 += 400;
	//d4.Print(); // 跨年

	//d4 += 4000;
	//d4.Print(); // 跨闰年

	(d4 + 4).Print(); // 利用返回值打印
	(d4 + 40).Print(); // 跨月
	(d4 + 400).Print(); // 跨年
	(d4 + 4000).Print(); // 跨闰年

	(d4++).Print();
	(++d4).Print();
	
	cout << (d5 - d4) << endl;
}

void TestDate3()
{
	int i = 0;
	double d = 1.1;
	Date d6(2022, 6, 8);
	cout << i << endl; // cout.operator<<(i); 库的底层用的是：运算符重载+函数重载
	cout << d << endl; // cout.operator<<(d);
	cout << d6; // 自己写，在全局中用友元函数，重载运算符<< 
}

void TestMenu()
{
	const char* WeeDayToStr[] = { "周一","周二","周三","周四","周五","周六","周日" };
	Date d1,d2;
	int day = 0;
	int option = 0;
	do
	{
		cout << "*******************************" << endl;
		cout << " 1、日期加/减天数 2、日期减日期" << endl;
		cout << " 3、日期->周几   -1、退出" << endl;
		cout << "*******************************" << endl;
		
		cout << "请输入:>";
		cin >> option;
		if (option == 1)
		{
			cout << "请依次输入日期和天数（减天数则输入负数）:";
			cin >> d1 >> day;  // 从 IO设备 提取到 对象和变量
			cout << "日期加减天数后的日期：" << d1 + day << endl;
		}
		else if (option == 2)
		{
			cout << "请依次输入两个日期:>";
			cin >> d1 >> d2;  // 从 IO设备 提取到 对象和变量
			cout << "相差的天数：" << d2 - d1 << endl;
		}
		else if (option == 3)
		{
			cout << "请输入日期:>";
			cin >> d1;
			Date start(1, 1, 1); // 公元元年
			int n = d1 - start; // 相差的天数
			int weekDay = 0;  // 周一  刚好对应数组下标
			weekDay += n;
			//cout << "周" << weekDay % 7 + 1 << endl;
			cout << WeeDayToStr[weekDay % 7]<< endl;

		}
		else
		{ 
			if (option != -1)
			{
				cout << "无此选项，请重新选择！" << endl;
			}
		}
	} while (option != -1);
}

void TestDate4()
{
	Date d1(2022, 8, 25);
	const Date d2(2022, 8, 25);
	d1.Print();
	d2.Print();

	d1 < d2;
	d2 < d1;

}

int main()
{
	//TestDate1();
	//TestDate2();
	//TestDate3();
	TestMenu();
	TestDate4();
	return 0;
}





