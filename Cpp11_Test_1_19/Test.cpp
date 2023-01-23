#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <array>
#include <assert.h>

using namespace std;

class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int year, int month, int day)" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

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


int main()
{
	//bit::string str1("hello");
	//bit::string str2(str1); //  ��������
	//bit::string str3(move(str1)); // �ƶ�����


	std::string s1("hello world");
	std::string s2(s1); // ��������

	// std::string s3(s1+s2);
	std::string s3 = s1 + s2; // �ƶ�����
	std::string s4 = move(s1);   // move()֮��s1����Դ�Ϳɱ�ת�ƣ�����ʹ��

	return 0;
}
