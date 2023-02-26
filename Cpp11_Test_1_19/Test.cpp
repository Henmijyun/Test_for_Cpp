#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <array>
#include <assert.h>
#include <algorithm>
#include <functional>

using namespace std;

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int year, int month, int day)" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//int main()
//{
//	int x1 = 1;
//	// 要能看懂，但是不建议使用
//	int x2 = { 2 };
//	int x3 { 2 };
//
//	// 都是在调用构造函数
//	Date d1(2022, 11, 22);
//	// C++11 要能看懂，但是不建议使用
//	Date d2 = {2022, 11, 11}; // ->调用构造函数
//	Date d3{ 2022, 11, 11 };
//
//	// 调用支持list (initializer_list<value_type> il）类似这样的构造函数
//	vector<int> v1 = { 1, 2, 3, 4, 5, 6 };
//	vector<int> v2 { 1, 2, 3, 4, 5, 6 };
//
//	list<int> lt1 = { 1, 2, 3, 4, 5, 6 };
//	list<int> lt2{ 1, 2, 3, 4, 5, 6 };
//
//	auto x = { 1, 2, 3, 4, 5, 6 };
//	cout << typeid(x).name() << endl;
//
//	vector<Date> v3 = {d1, d2, d3};
//	vector<Date> v4 = { { 2022, 1, 1 }, {2022, 11, 11} };
//
//	string s1 = "11111";
//
//	// 构造
//	map<string, string> dict = { { "sort", "排序" }, { "insert", "插入" } };
//
//	// 赋值重载
//	initializer_list<pair<const string, string>> kvil = { { "left", "左边" }, { "left", "左边" } };
//	dict = kvil;
//
//	return 0;
//}


//int main()
//{
//	int x = 10;
//
//	// typeid拿到只是类型的字符串，不能用这个再去定义对象什么的
//	//typeid(x).name() y = 20;
//
//	decltype(x) y1 = 20.22;
//	auto y2 = 20.22;
//
//	cout << y1 << endl;
//	cout << y2 << endl;
//
//	return 0;
//}


//int main()
//{
//	const size_t N = 100;
//	int a1[N];
//
//	// C语言数组越界检查，越界读基本检查不出来，越界写是抽查
//	a1[N];
//	//a1[N] = 1;
//	a1[N + 5] = 1;
//
//
//	// 越界读写都可以被检查出来
//	// 实际情况：array用得很少，一方面大家用c数组用惯了
//	// 用array不如用vector + resize去替代c数组
//
//	array<int, N> a2;
//	a2[N];
//	a2[N] = 1;
//	a2[N + 5] = 1;
//
//	return 0;
//}



namespace skk
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 拷贝构造(深拷贝)" << endl;

			//string tmp(s._str);
			//swap(s);

			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}

		// 移动构造
		string(string&& s)  // 右值引用   参数为将亡值
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- 资源转移" << endl;
			swap(s);
		}

		// 拷贝赋值
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- 拷贝赋值(深拷贝)" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}

		// 移动赋值
		string& operator=(string&& s)
		{
			cout << "string& operator=(string s) -- 移动赋值(资源移动)" << endl;
			swap(s);

			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}

skk::string to_string(int value)
{
	bool flag = true;
	if (value < 0)
	{
		flag = false;
		value = 0 - value;
	}

	skk::string str;
	while (value > 0)
	{
		int x = value % 10;
		value /= 10;

		str += ('0' + x);
	}

	if (flag == false)
	{
		str += '-';
	}

	std::reverse(str.begin(), str.end());
	return str;
}

//// 拷贝构造和移动构造
//int main()
//{
//	bit::string ret = to_string(-3456);
//
//	bit::string s1("1111111");
//	bit::string s2(s1);
//
//	return 0;
//}


// 拷贝赋值和移动赋值
//int main()
//{
//	bit::string ret("1111111111111111111111111");
//	//...
//	ret = to_string(-3456);
//
//	return 0;
//}


//int main()
//{
//	//bit::string str1("hello");
//	//bit::string str2(str1); //  拷贝构造
//	//bit::string str3(move(str1)); // 移动构造
//
//
//	std::string s1("hello world");
//	std::string s2(s1); // 拷贝构造
//
//	// std::string s3(s1+s2);
//	std::string s3 = s1 + s2; // 移动构造
//	std::string s4 = move(s1);   // move()之后，s1的资源就可被转移，谨慎使用
//
//	return 0;
//}


//// 要求delete关键字实现，一个类，只能在堆上创建对象
//class HeapOnly
//{
//public:
//	HeapOnly()
//	{
//		_str = new char[10];
//	}
//
//	~HeapOnly() = delete;
//
//	void Destroy()
//	{
//		delete[] _str;
//
//		operator delete(this);
//	}
//
//private:
//	char* _str;
//	// ..
//};
//
//int main()
//{
//	// HeapOnly hp1;  // 栈  err
// 	// static HeapOnly hp2;  // 静态区  err
//
//	HeapOnly* ptr = new HeapOnly;  // 堆  因为在
//
//	ptr->Destroy();
//	// operator delete(ptr); // OK
//	return 0;
//}
//



//// 可变参数的函数模板
//template<class ...Args>
//void ShowList(Args... args)
//{
//	cout << sizeof...(args) << endl;
//
//	// 不支持下面这样写，去读数据包中的数据 err
//	//for (int i = 0; i < sizeof...(args); ++i)
//	//{
//	//	cout << args[i] << " ";
//	//}
//	//cout << endl;
//}
//
//int main()
//{
//	string str("hello");
//	ShowList();
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', str);
//
//	return 0;
//}


//void ShowList()  // 递归到零个参数时，匹配这个函数，相当于结束递归
//{
//	cout << endl;
//}
//
//// Args... args  代表N个参数包 （N >= 0）
//template<class T, class ...Args>
//void ShowList(const T& val, Args... args)
//{
//	cout << "ShowList(" << val << ", " << sizeof...(args) << "参数包)" << endl;
//
//	ShowList(args...);  // 每次递归的传参都会-1， 编译时递归，不是运行时递归
//}
//
//int main()
//{
//	string str("hello");
//	ShowList(1, 'A', str);
//	ShowList(1, 'A', str, 5.555, "asdasf");
//
//	return 0;
//}



void ShowList()  // 递归到零个参数时，匹配这个函数，相当于结束递归
{
	cout << endl;
}

template<class T>
int PrintArg(const T& x)
{
	cout << x << " ";
	return 0;
}

template<class ...Args>
void ShowList(Args... args)
{
	//int a[] = { (PrintArg(args), 0)... }; // 逗号表达式，初始化出来的实际值为0 ，函数返回值void
	int a[] = { PrintArg(args)... };  // 利用每次传参进行打印，函数返回值0
	cout << endl;
}

//int main()
//{
//	string str("hello");
//	ShowList(1, 'A', str);
//	ShowList(1, 'A', str, 5.555, "asdasf");
//
//	return 0;
//}



class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int year = 1, int month = 1, int day = 1)" << endl;
	}

	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date(const Date& d)" << endl;
	}

	Date& operator=(const Date& d)
	{
		cout << "Date& operator=(const Date& d))" << endl;
		return *this;
	}

private:
	int _year;
	int _month;
	int _day;
};

//int main()
//{
//	// 没有区别
//	vector<int> v1;
//	v1.push_back(1);
//	v1.emplace_back(2);
//
//	/*vector<pair<bit::string, int>> v2;
//	v2.push_back(make_pair("sort", 1));
//
//	v2.emplace_back(make_pair("sort", 1));
//	v2.emplace_back("sort", 1);*/
//
//	/*vector<Date> v3;
//	v3.push_back(Date(2022,11,16));
//
//	cout <<"---------------------------------"<<endl;
//	v3.emplace_back(2022, 11, 16);*/
//
//	list<Date> lt1;
//	lt1.push_back(Date(2022, 11, 16));
//
//	cout << "---------------------------------" << endl;
//	lt1.emplace_back(2022, 11, 16);
//
//	return 0;
//}



struct Goods
{
	string _name;  // 名字
	double _price; // 价格
	int _evaluate; // 评价
	//...

	Goods(const char* str, double price, int evaluate)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{}
};

//struct ComparePriceLess
struct Compare1
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price < gr._price;
	}
};

//struct ComparePriceGreater
struct Compare2
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price > gr._price;
	}
};

//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3 }, { "菠萝", 1.5, 4 } };
//
//	/*sort(v.begin(), v.end(), ComparePriceLess());
//	sort(v.begin(), v.end(), ComparePriceGreater());*/
//
//	//sort(v.begin(), v.end(), Compare1());
//	//sort(v.begin(), v.end(), Compare2());
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._name < g2._name; });
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._name > g2._name; });
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._price < g2._price; });
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._price > g2._price; });
//}
//
//int main()
//{
//	// 两个数相加的lambda
//	auto add1 = [](int a, int b)->int{return a + b; };
//	cout << add1(1, 2) << endl;
//
//	// 省略返回值
//	auto add2 = [](int a, int b){return a + b; };
//	cout << add2(1, 2) << endl;
//
//	// 交换变量的lambda
//	int x = 0, y = 1;
//	auto swap1 = [](int& x1, int& x2)->void{int tmp = x1; x1 = x2; x2 = tmp; };
//	swap1(x, y);
//	cout << x << ":" << y << endl;
//
//	// 可以函数形式去写
//	auto swap2 = [](int& x1, int& x2)
//	{
//		int tmp = x1;
//		x1 = x2;
//		x2 = tmp;
//	};
//
//	swap2(x, y);
//	cout << x << ":" << y << endl;
//
//	// 不传参数交换x y的lambda  -- 捕捉列表
//	// 默认捕捉的对象不能修改
//	/*auto swap3 = [x, y]()mutable   // 传值，但是出了lambda作用域就销毁了
//	{
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//
//	swap3();
//	cout << x << ":" << y << endl;*/
//
//	auto swap3 = [&x, &y]    // 引用，直接改变x和y本身
//	{
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//
//	swap3();
//	cout << x << ":" << y << endl;
//
//
//	return 0;
//}



//int f = 1;
//int main()
//{
//	int a, b, c, d;
//	a = b = c = d = 1;
//
//	// 全部传值捕捉
//	auto f1 = [=]()->void {
//		cout << a << b << c << d << endl;
//	};  // lambda匿名函数的定义
//	f1(); // lambda匿名函数的调用
//
//	// 混合捕捉
//	auto f2 = [=, &a]()->void {
//		cout << a << b << c << d << endl;
//	};
//	f2();
//
//	auto f3 = [&, a, b](){
//		c++;
//		d++;
// 		f++;  // 全局的也可以捕捉
//		cout << a << b << c << d << endl;
//	};
//	f3();
//	return 0;
//}


class Rate
{
public:
	Rate(double rate) : _rate(rate)
	{}

	double operator()(double money, int year)
	{
		return money * _rate * year;
	}

private:
	double _rate;
};

// lambda_uuid
class lambda_xxxx
{

};

//int main()
//{
//	// 函数对象
//	double rate = 0.49;
//	Rate r1(rate);
//	r1(10000, 2);
//
//	// 仿函数lambda_uuid
//	// lambda -> lambda_uuid
//	auto r2 = [=](double monty, int year)->double{return monty*rate*year; };
//	r2(10000, 2);
//
//	auto r3 = [=](double monty, int year)->double{return monty*rate*year; };
//	r3(10000, 2);
//
//	return 0;
//}


//template<class F, class T>
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//	return f(x);
//}
//
//double f(double i)
//{
//	return i / 2;
//}
//
//struct Functor
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
//};

//




//int f(int a, int b) // 函数
//{
//	return a + b;
//}
//
//struct Functor
//{
//public:
//	int operator() (int a, int b) // 仿函数
//	{
//		return a + b;
//	}
//};
//
//class Plus
//{
//public:
//	static int plusi(int a, int b)  // 静态
//	{
//		return a + b;
//	}
//	double plusd(double a, double b)  // 非静态
//	{
//		return a + b;
//	}
//};
//
//int main()
//{
//	// 包装器
//	// 传参的时候，传 返回值类型 和 参数包
//
//	function<int(int, int)> f1 = f;   // 绑定函数
//	f1(1, 2);
//
//	function<int(int, int)> f2 = Functor();  // 绑定仿函数
//	f2(1, 2);
//
//	function<int(int, int)> f3 = Plus::plusi;   // 绑定类中的，静态函数
//	f3(1, 2);
//
//	function<double(Plus, double, double)> f4 = &Plus::plusd;   // 绑定类中的，非静态函数 （语法规定要加&）
//	f4(Plus(), 1.1, 2.2);   // (成员函数要通过对象来调用，所以需要传对象)
//	 
//	return 0;
//}



//template<class F, class T>
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//	return f(x);
//}
//
//double f(double i)
//{
//	return i / 2;
//}
//
//struct Functor
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
//};
//int main()
//{
//	// 编译器会分别实例化出三个函数
//	// 函数指针
//	cout << useF(f, 11.11) << endl;
//	// 函数对象
//	cout << useF(Functor(), 11.11) << endl;
//	// lamber表达式对象
//	cout << useF([](double d)->double{ return d / 4; }, 11.11) << endl;
//
//	cout << "-------------" << endl;
//	// 使用包装器，只实例化出一个
//	// 函数指针
//	function<double(double)> f1 = f;
//	cout << useF(f1, 11.11) << endl;
//
//	// 函数对象
//	function<double(double)> f2 = Functor();
//	cout << useF(f2, 11.11) << endl;
//
//	// lamber表达式对象
//	function<double(double)> f3 = [](double d)->double { return d / 4; };
//	cout << useF(f3, 11.11) << endl;
//
//	return 0;
//}



// bind 绑定

int Div(int a, int b)
{
	return a / b;
}

int Plus(int a, int b)
{
	return a + b;
}

int Mul(int a, int b, double rate)  // 三个参数
{
	return a * b * rate;
}

class Sub
{
public:
	int sub(int a, int b)  // 类中的函数
	{
		return a - b;
	}
};

using namespace placeholders;


int main()
{
	// 调整个数, 绑定死固定参数
	function<int(int, int)> funcPlus = Plus;
	//function<int(Sub, int, int)> funcSub = &Sub::sub;
	function<int(int, int)> funcSub = bind(&Sub::sub, Sub(), _1, _2); // 第一个参数Sub()是lambda的类，被绑定住
	function<int(int, int)> funcMul = bind(Mul, _1, _2, 1.5);  // 第三个参数给固定值
	map<string, function<int(int, int)>> opFuncMap =
	{
		{ "+", Plus},
		{ "-", bind(&Sub::sub, Sub(), _1, _2)}
	};

	cout << funcPlus(1, 2) << endl;
	cout << funcSub(1, 2) << endl;  // 绑定调整后，类不需要传参
	cout << funcMul(2, 2) << endl; // 绑定调整后只需要传参2个值

	cout << opFuncMap["+"](1, 2) << endl;
	cout << opFuncMap["-"](1, 2) << endl;



	int x = 2, y = 10;
	cout << Div(x, y) << endl;

	// 调整顺序 -- 鸡肋
	// _1 _2.... 定义在placeholders命名空间中，代表绑定函数对象的形参，
	// _1，_2...分别代表第一个形参、第二个形参...
	//bind(Div, placeholders::_1, placeholders::_2); // 不放开命名空间的话
	auto bindFunc1 = bind(Div, _1, _2);
	function<int(int, int)> bindFunc2 = bind(Div, _2, _1);
	cout << bindFunc1(x, y) << endl;
	cout << bindFunc2(x, y) << endl;

	return 0;
}

