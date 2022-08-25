

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
// 不用Init，改用构造函数
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
// 构造函数可以函数重载 ，但是 无参数 和 全缺省 不可以重复定义。
 
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
	//		perror("malloc申请空间失败!!!");
	//		return;
	//	}
	//	_capacity = capacity;
	//	_size = 0;
	//}
// 构造函数
	Stack(size_t capacity = 4)
	{
		_array = (DataType*)malloc(sizeof(DataType) * capacity);
		if (NULL == _array)
		{
			perror("malloc申请空间失败!!!");
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

// 调用Init初始化，可能会忘记！导致崩溃出现随机值。
// 能不能保证对象一定被初始化？ -- 构造函数
int main()
{
	//Date d1;
	//d1.Init(2022, 8, 24);

	Date d1(2022, 8, 24);
	Date d2;

	Stack st;

	return 0;
}


