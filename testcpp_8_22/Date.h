#pragma once


//日期类的声明
#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
	// 友元函数 -- 这个函数内部可以使用当前对象访问私有保护成员。
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:

	bool CheckDate()
	{
		if (_year >= 1
			&& _month > 0 && _month < 13
			&& _day > 0 && _day <= GetMonthDay(_year, _month))
		{
			return true;
		}
		else
			return false;
	}
	// 全缺省的构造函数
	// 构造函数会频繁调用，所以直接放在类里面定义作为inline
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;

		//if (!CheckDate())  // !this->CheckDate()
		//{
		//	Print();
		//	cout << "刚构造的日期非法" << endl;
		//}

		assert(CheckDate()); // 防止日期非法
	}

	// 拷贝构造函数
	// d2(d1)
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// 赋值运算符重载
	// d1 = d3 -> d1.operator=(&d1, d3)
	Date& operator=(const Date& d)
	{
		if (this != &d) // 判断地址不相等，才赋值
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
		// 这里的this指向类d1，作用域不是当前函数，出了当前函数不会销毁。
		// 因此可以用 引用 做返回。
	}

	// 析构函数
	~Date()
	{
		_year = 0;
		_month = 0;
		_day = 0;
		// 没开空间，其实不写析构函数也行。
	}


	// 获取某年某月的天数
	// 会频繁调用，所以直接放在类里面定义作为inline
	int GetMonthDay(int year, int month)
	{
		// 频繁调用 static 不会重复建立数组
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) //区分闰年
		{
			day += 1; // 区分闰年的二月
		}
		return day; // 返回当月的天数
	}

	// 日期+=天数
	Date& operator+=(int day); 
	// 日期+天数
	Date operator+(int day)const;

	// ++d1; 和  d1++;
	// 直接按特性重载，无法区分
	// 特殊处理，使用重载区分，后置++重载增加一个int参数跟前置构成函数重载进行区分
	
	// 前置++
	Date& operator++();
	// 后置++
	Date operator++(int);
	// 后置--
	Date operator--(int);
	// 前置--
	Date& operator--();
	// 日期-天数
	Date operator-(int day)const;
	// 日期-=天数
	Date& operator-=(int day);
	// 日期-日期 返回天数
	int operator-(const Date& d)const;



	// >运算符重载
	bool operator>(const Date& d)const;
	// ==运算符重载
	bool operator==(const Date& d)const;
	// >=运算符重载
	bool operator >= (const Date& d)const;
	// <运算符重载
	bool operator < (const Date& d)const;
	// <=运算符重载
	bool operator <= (const Date& d)const;
	// !=运算符重载
	bool operator != (const Date& d)const;

	// 变成 void Print(const Date* const this) 
	void Print()const
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	//// << 运算符重载
	//void operator<<(ostream& out);

private:
	int _year;
	int _month;
	int _day;
};

// 流插入 << 运算符重载 全局 （友元）
// 因为cout在类中不可以作为左操作数，左操作数固定为this，所以定义在全局中。
// 全局中无法访问类中的私有成员，所以需要用友元函数来实现访问私有。
// 全局重载 + 友元函数，实现： cout << d1;
// 带返回值可 cout << d1 << d2; 连续使用
inline ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}

// 流提取 >> 运算符重载 全局 （友元）
// 从 流 中提取内容到 类 中
inline istream& operator>>(istream& in, Date& d) 
{
	in >> d._year >> d._month >> d._day;
	assert(d.CheckDate()); // 判断输入是否合法
	return in;
}

class Stack
{
};

//构造、拷贝构造、赋值重载、析构，默认生成都可以用。
class MyQueue
{
private:
	Stack _st1;
	Stack _st2;
};


