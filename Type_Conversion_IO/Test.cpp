#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <fstream>      // std::ifstream

using namespace std;


//void Insert(size_t pos, char ch)
//{
//	size_t _size = 10;
//	int end = _size - 1;
//	while (end >= pos)    // end 隐式类型转换
//	{
//		// _str[end + 1] = _str[end];
//		--end;
//	}
//}
//
//void Test()
//{
//	int i = 1;
//	// 隐式类型转换(意义相近的类型)
//	double d = i;
//	printf("%d, %.2f\n", i, d);
//
//	int* p = &i;
//	// 显示的强制类型转换（意义不相近的类型，值转换后有意义）
//	int address = (int)p;
//	printf("%x, %d\n", p, address);
//
//	Insert(5, 'a');	
//	Insert(0, 'a');
//
//}



//int main()
//{
//	Test();
//	return 0;
//}



//int mian()
//{
//	double d = 12.46;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//
//	// int* p = &a;
//	// 不支持
//	// int address = static_cast<int>(p);
//	
//
//	int* p = &a;
//	int address = reinterpret_cast<int>(p);
//
//	return 0;
//}







//class A
//{
//public:
//	virtual void f(){}  // 父类必须要有虚函数
//public:
//	int _a = 0;
//};
//
//class B : public A
//{
//public:
//	int _b = 1;
//};
//
//// A*的指针有可能指向父类，有可能指向子类
//void func(A* pa)
//{
//	// dynamic_cast 会先检查是否能转换成功，能成功则转换，不能则返回
//	// B* pb1 = static_cast<B*>(pa);	
//	// B* pb2 = dynamic_cast<B*>(pa);
//
//	// cout << "pb1: " << pb1 << endl;
//	// cout << "pb2: " << pb2 << endl;
//
//
//	/*B* pb = (B*)pa;
//	pa->_a++;
//	pb->_b++;*/
//
//	// 如果pa指向子类，可以转换， 转换表达式返回正确的地址
//	// 如果pa指向父类，那么不能转换，转换表达式返回nullptr
//	
//	B* pb = dynamic_cast<B*>(pa);
//	if (pb)
//	{
//		cout << "转换成功" << endl;
//		pb->_a++;
//		pb->_b++;
//		cout << pb->_a << ":" << pb->_b << endl;
//	}
//	else
//	{
//		cout << "转换失败" << endl;
//		pa->_a++;
//		cout << pa->_a << endl;
//
//	}
//
//
//}

//int main()
//{
//	A aa;
//	// 父类对象无论如何不可以转换为子类
//	// B bb = dynamic_cast<B>(aa);
//	// B bb = (B)aa;
//
//	B bb;
//	func(&aa);
//	func(&bb);
//
//
//	return 0;
//}





//int main()
//{
//	const int a = 2;     // C++的const是存在栈区
//	int* p = const_cast<int*>(&a);
//	// int* p = (int*)&a;  // ok
//	*p = 3;
//
//	cout << a << endl;   // 2
//	cout << *p << endl;  // 3
// 
//
//	int i = 0;
//	double d = i;
//
//	const double& rd1 = i;
//	const double& rd2 = static_cast<double>(i);
//	
//	B bb;
//	A aa = bb;
//	A& ra1 = bb;
//
//
//
//	return 0;
//}


//class A1
//{
//public:
//	virtual void f(){}
//public:
//	int _a1 = 0;
//};
//
//class A2
//{
//public:
//	virtual void f(){}
//public:
//	int _a2 = 0;
//};
//
//class B : public A1, public A2
//{
//public:
//	int _b = 1;
//};
//
//int main()
//{
//	B bb;
//	A1* ptr1 = &bb;
//	A2* ptr2 = &bb;
//	cout << ptr1 << endl;
//	cout << ptr2 << endl << endl;
//
//	B* pb1 = (B*)ptr1;
//	B* pb2 = (B*)ptr2;
//	cout << pb1 << endl;
//	cout << pb2 << endl << endl;
//
//	B* pb3 = dynamic_cast<B*>(ptr1);
//	B* pb4 = dynamic_cast<B*>(ptr2);
//	cout << pb3 << endl;
//	cout << pb4 << endl << endl;
//
//	return 0;
//}








// IO///////////////////////


// printf/scanf     
// fprintf/fscanf   // 针对文件
// sprintf/sscanf   // 针对字符串

//int main()
//{
//	int a = 0;
//	printf("%d\n", a);
//
//	scanf("%d", &a);
//	printf("%d\n", a);
//
//	return 0;
//}


// ostream/istream 更好支持自定义类型对象的流插入和流提取
// 自定义类型，可以自己重载，控制流提取和流插入的方式
//
//int main()
//{
//	/*int i = 1;
//	double j = 2.2;
//	cout << i << j << endl;*/
//
//	// 2022 11 28
//	// 输入多个值，默认都是用空格或者换行分割
//	int year, month, day;
//	//cin >> year >> month >> day;
//	//scanf("%d%d%d", &year, &month, &day);
//	//scanf("%d %d %d", &year, &month, &day); //不需要去加空格
//
//	// 20221128
//	//scanf("%4d%2d%2d", &year, &month, &day);
//	// 
//	//string str;
//	//cin >> str;
//	//year = stoi(str.substr(0, 4));
//	//month = stoi(str.substr(4, 2));
//	//day = stoi(str.substr(6, 2));
//
//	return 0;
//}


//// 有多行测试用例
//int main()
//{
//	int year, month, day;
//
//	string str;
//	while (cin >> str)
//	{
//		year = stoi(str.substr(0, 4));
//		month = stoi(str.substr(4, 2));
//		day = stoi(str.substr(6, 2));
//
//		cout << year << "年" << month << "月" << day << "日" << endl;
//	}
//
//	return 0;
//}

//
//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//
//	operator int()
//	{
//		return _a;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	// 内置类型 转换成自定义类型
//	A aa1 = 1; // 隐式类型转换 用1构造A临时对象，再拷贝构造aa1，优化后直接1构造aa1
//
//	// 自定义类型 转换成内置类型
//	int i = aa1;
//
//	return 0;
//}



//class Date
//{
//	friend ostream& operator << (ostream& out, const Date& d);
//	friend istream& operator >> (istream& in, Date& d);
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	operator bool()
//	{
//		// 这里是随意写的，假设输入_year为0，则结束
//		if (_year == 0)
//			return false;
//		else
//			return true;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//istream& operator >> (istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
//ostream& operator << (ostream& out, const Date& d)
//{
//	out << d._year << " " << d._month << " " << d._day;
//	return out;
//}
//// C++ IO流，使用面向对象+运算符重载的方式
//// 能更好的兼容自定义类型，流插入和流提取
//int main()
//{
//	// 自动识别类型的本质--函数重载
//	// 内置类型可以直接使用--因为库里面ostream类型已经实现了
//	int i = 1;
//	double j = 2.2;
//	cout << i << endl;
//	cout << j << endl;
//	// 自定义类型则需要我们自己重载<< 和 >>
//	Date d(2022, 4, 10);
//	cout << d;
//	while (d)
//	{
//		cin >> d;
//		cout << d;
//	}
//	return 0;
//}



class Date
{
	friend ostream& operator << (ostream& out, const Date& d);
	friend istream& operator >> (istream& in, Date& d);
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	operator bool()
	{
		// 这里是随意写的，假设输入_year为0，则结束
		if (_year == 0)
			return false;
		else
			return true;
	}
private:
	int _year;
	int _month;
	int _day;
};

istream& operator >> (istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}

ostream& operator << (ostream& out, const Date& d)
{
	out << d._year << " " << d._month << " " << d._day;
	return out;
}


//int main()
//{
//	ifstream ifs("Test.cpp");
//	char ch = ifs.get();
//	while (ifs)    // 隐式类型转换bool，基类ios实现的，fstream继承
//	{
//		cout << ch;
//		ch = ifs.get();
//	}
//
//	// 析构函数会自动close
//
//	return 0;
//}

int main()
{
	ifstream ifs("test.txt");
	// fscanf("%d%s%f", )

	int i;
	string s;
	double d;
	Date de;
	ifs >> i >> s >> d >> de;

	return 0;
}