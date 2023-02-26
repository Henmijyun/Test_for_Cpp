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
//	// Ҫ�ܿ��������ǲ�����ʹ��
//	int x2 = { 2 };
//	int x3 { 2 };
//
//	// �����ڵ��ù��캯��
//	Date d1(2022, 11, 22);
//	// C++11 Ҫ�ܿ��������ǲ�����ʹ��
//	Date d2 = {2022, 11, 11}; // ->���ù��캯��
//	Date d3{ 2022, 11, 11 };
//
//	// ����֧��list (initializer_list<value_type> il�����������Ĺ��캯��
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
//	// ����
//	map<string, string> dict = { { "sort", "����" }, { "insert", "����" } };
//
//	// ��ֵ����
//	initializer_list<pair<const string, string>> kvil = { { "left", "���" }, { "left", "���" } };
//	dict = kvil;
//
//	return 0;
//}


//int main()
//{
//	int x = 10;
//
//	// typeid�õ�ֻ�����͵��ַ����������������ȥ�������ʲô��
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
//	// C��������Խ���飬Խ���������鲻������Խ��д�ǳ��
//	a1[N];
//	//a1[N] = 1;
//	a1[N + 5] = 1;
//
//
//	// Խ���д�����Ա�������
//	// ʵ�������array�õú��٣�һ��������c�����ù���
//	// ��array������vector + resizeȥ���c����
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

		// ��������
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- ��������(���)" << endl;

			//string tmp(s._str);
			//swap(s);

			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}

		// �ƶ�����
		string(string&& s)  // ��ֵ����   ����Ϊ����ֵ
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- ��Դת��" << endl;
			swap(s);
		}

		// ������ֵ
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- ������ֵ(���)" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}

		// �ƶ���ֵ
		string& operator=(string&& s)
		{
			cout << "string& operator=(string s) -- �ƶ���ֵ(��Դ�ƶ�)" << endl;
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

//// ����������ƶ�����
//int main()
//{
//	bit::string ret = to_string(-3456);
//
//	bit::string s1("1111111");
//	bit::string s2(s1);
//
//	return 0;
//}


// ������ֵ���ƶ���ֵ
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
//	//bit::string str2(str1); //  ��������
//	//bit::string str3(move(str1)); // �ƶ�����
//
//
//	std::string s1("hello world");
//	std::string s2(s1); // ��������
//
//	// std::string s3(s1+s2);
//	std::string s3 = s1 + s2; // �ƶ�����
//	std::string s4 = move(s1);   // move()֮��s1����Դ�Ϳɱ�ת�ƣ�����ʹ��
//
//	return 0;
//}


//// Ҫ��delete�ؼ���ʵ�֣�һ���ֻ࣬���ڶ��ϴ�������
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
//	// HeapOnly hp1;  // ջ  err
// 	// static HeapOnly hp2;  // ��̬��  err
//
//	HeapOnly* ptr = new HeapOnly;  // ��  ��Ϊ��
//
//	ptr->Destroy();
//	// operator delete(ptr); // OK
//	return 0;
//}
//



//// �ɱ�����ĺ���ģ��
//template<class ...Args>
//void ShowList(Args... args)
//{
//	cout << sizeof...(args) << endl;
//
//	// ��֧����������д��ȥ�����ݰ��е����� err
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


//void ShowList()  // �ݹ鵽�������ʱ��ƥ������������൱�ڽ����ݹ�
//{
//	cout << endl;
//}
//
//// Args... args  ����N�������� ��N >= 0��
//template<class T, class ...Args>
//void ShowList(const T& val, Args... args)
//{
//	cout << "ShowList(" << val << ", " << sizeof...(args) << "������)" << endl;
//
//	ShowList(args...);  // ÿ�εݹ�Ĵ��ζ���-1�� ����ʱ�ݹ飬��������ʱ�ݹ�
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



void ShowList()  // �ݹ鵽�������ʱ��ƥ������������൱�ڽ����ݹ�
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
	//int a[] = { (PrintArg(args), 0)... }; // ���ű��ʽ����ʼ��������ʵ��ֵΪ0 ����������ֵvoid
	int a[] = { PrintArg(args)... };  // ����ÿ�δ��ν��д�ӡ����������ֵ0
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
//	// û������
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
	string _name;  // ����
	double _price; // �۸�
	int _evaluate; // ����
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
//	vector<Goods> v = { { "ƻ��", 2.1, 5 }, { "�㽶", 3, 4 }, { "����", 2.2, 3 }, { "����", 1.5, 4 } };
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
//	// ��������ӵ�lambda
//	auto add1 = [](int a, int b)->int{return a + b; };
//	cout << add1(1, 2) << endl;
//
//	// ʡ�Է���ֵ
//	auto add2 = [](int a, int b){return a + b; };
//	cout << add2(1, 2) << endl;
//
//	// ����������lambda
//	int x = 0, y = 1;
//	auto swap1 = [](int& x1, int& x2)->void{int tmp = x1; x1 = x2; x2 = tmp; };
//	swap1(x, y);
//	cout << x << ":" << y << endl;
//
//	// ���Ժ�����ʽȥд
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
//	// ������������x y��lambda  -- ��׽�б�
//	// Ĭ�ϲ�׽�Ķ������޸�
//	/*auto swap3 = [x, y]()mutable   // ��ֵ�����ǳ���lambda�������������
//	{
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//
//	swap3();
//	cout << x << ":" << y << endl;*/
//
//	auto swap3 = [&x, &y]    // ���ã�ֱ�Ӹı�x��y����
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
//	// ȫ����ֵ��׽
//	auto f1 = [=]()->void {
//		cout << a << b << c << d << endl;
//	};  // lambda���������Ķ���
//	f1(); // lambda���������ĵ���
//
//	// ��ϲ�׽
//	auto f2 = [=, &a]()->void {
//		cout << a << b << c << d << endl;
//	};
//	f2();
//
//	auto f3 = [&, a, b](){
//		c++;
//		d++;
// 		f++;  // ȫ�ֵ�Ҳ���Բ�׽
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
//	// ��������
//	double rate = 0.49;
//	Rate r1(rate);
//	r1(10000, 2);
//
//	// �º���lambda_uuid
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




//int f(int a, int b) // ����
//{
//	return a + b;
//}
//
//struct Functor
//{
//public:
//	int operator() (int a, int b) // �º���
//	{
//		return a + b;
//	}
//};
//
//class Plus
//{
//public:
//	static int plusi(int a, int b)  // ��̬
//	{
//		return a + b;
//	}
//	double plusd(double a, double b)  // �Ǿ�̬
//	{
//		return a + b;
//	}
//};
//
//int main()
//{
//	// ��װ��
//	// ���ε�ʱ�򣬴� ����ֵ���� �� ������
//
//	function<int(int, int)> f1 = f;   // �󶨺���
//	f1(1, 2);
//
//	function<int(int, int)> f2 = Functor();  // �󶨷º���
//	f2(1, 2);
//
//	function<int(int, int)> f3 = Plus::plusi;   // �����еģ���̬����
//	f3(1, 2);
//
//	function<double(Plus, double, double)> f4 = &Plus::plusd;   // �����еģ��Ǿ�̬���� ���﷨�涨Ҫ��&��
//	f4(Plus(), 1.1, 2.2);   // (��Ա����Ҫͨ�����������ã�������Ҫ������)
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
//	// ��������ֱ�ʵ��������������
//	// ����ָ��
//	cout << useF(f, 11.11) << endl;
//	// ��������
//	cout << useF(Functor(), 11.11) << endl;
//	// lamber���ʽ����
//	cout << useF([](double d)->double{ return d / 4; }, 11.11) << endl;
//
//	cout << "-------------" << endl;
//	// ʹ�ð�װ����ֻʵ������һ��
//	// ����ָ��
//	function<double(double)> f1 = f;
//	cout << useF(f1, 11.11) << endl;
//
//	// ��������
//	function<double(double)> f2 = Functor();
//	cout << useF(f2, 11.11) << endl;
//
//	// lamber���ʽ����
//	function<double(double)> f3 = [](double d)->double { return d / 4; };
//	cout << useF(f3, 11.11) << endl;
//
//	return 0;
//}



// bind ��

int Div(int a, int b)
{
	return a / b;
}

int Plus(int a, int b)
{
	return a + b;
}

int Mul(int a, int b, double rate)  // ��������
{
	return a * b * rate;
}

class Sub
{
public:
	int sub(int a, int b)  // ���еĺ���
	{
		return a - b;
	}
};

using namespace placeholders;


int main()
{
	// ��������, �����̶�����
	function<int(int, int)> funcPlus = Plus;
	//function<int(Sub, int, int)> funcSub = &Sub::sub;
	function<int(int, int)> funcSub = bind(&Sub::sub, Sub(), _1, _2); // ��һ������Sub()��lambda���࣬����ס
	function<int(int, int)> funcMul = bind(Mul, _1, _2, 1.5);  // �������������̶�ֵ
	map<string, function<int(int, int)>> opFuncMap =
	{
		{ "+", Plus},
		{ "-", bind(&Sub::sub, Sub(), _1, _2)}
	};

	cout << funcPlus(1, 2) << endl;
	cout << funcSub(1, 2) << endl;  // �󶨵������಻��Ҫ����
	cout << funcMul(2, 2) << endl; // �󶨵�����ֻ��Ҫ����2��ֵ

	cout << opFuncMap["+"](1, 2) << endl;
	cout << opFuncMap["-"](1, 2) << endl;



	int x = 2, y = 10;
	cout << Div(x, y) << endl;

	// ����˳�� -- ����
	// _1 _2.... ������placeholders�����ռ��У�����󶨺���������βΣ�
	// _1��_2...�ֱ�����һ���βΡ��ڶ����β�...
	//bind(Div, placeholders::_1, placeholders::_2); // ���ſ������ռ�Ļ�
	auto bindFunc1 = bind(Div, _1, _2);
	function<int(int, int)> bindFunc2 = bind(Div, _2, _1);
	cout << bindFunc1(x, y) << endl;
	cout << bindFunc2(x, y) << endl;

	return 0;
}

