#define _CRT_SECURE_NO_WARNINGS 1

//日期类的定义
#include "Date.h"



// 日期+=天数
Date& Date::operator+=(int day) // 返回值加&引用，不生成拷贝，也不出类的作用域，所以类不会销毁
{
	if (day < 0)
	{
		return *this -= -day;
	}

	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;

		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this; // 因为this指向类，解引用则得到类
}

// 日期+天数
Date Date::operator+(int day)const
{
	Date ret(*this); // 为了不影响前一个类的值，拷贝一个新类出来。
	// 这里是浅拷贝，析构函数会运行两次。

	// 复用
	ret += day;

	return ret; // 返回这个拷贝出来的类
}

// 前置++
Date& Date::operator++()
{
	return *this += 1;
}

// 后置++
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;

	return tmp;
}



// 前置--
Date& Date::operator--()
{
	return *this -= 1;
}

// 后置--
Date Date::operator--(int)
{
	Date tmp(*this); // 拷贝构造
	*this -= 1;
	return tmp;  // 传值返回又有一次拷贝
}

// 日期-日期 返回天数
int Date::operator-(const Date& d)const
{
	int flag = 1;   // 控制返回值的正负数
	Date max = *this;  // 默认*this日期为大
	Date min = d;
	if (*this < d)  // 反则调整
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int n = 0;
	while (min != max)
	{
		++min;
		++n;  // 记录天数
	}
	return flag * n;
}

// 日期-天数 
Date Date::operator-(int day)const
{
	Date ret = *this;
	ret -= day;
	return ret;
}

// 日期-=天数
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}

	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}



// >运算符重载  d1 > d2
bool Date::operator>(const Date& d)const
{
	if ((_year > d._year)
		|| (_year == d._year && _month > d._month)
		|| (_year == d._year && _month == d._month && _day > d._day))
	{
		return true;
	}
	else
		return false;
}

// ==运算符重载
bool Date::operator==(const Date& d)const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

// >=运算符重载
bool Date::operator >= (const Date& d)const
{
	return (*this > d) || (*this == d);
}

// <运算符重载
bool Date::operator < (const Date& d)const
{
	return !(*this >= d);
}

// <=运算符重载
bool Date::operator <= (const Date& d)const
{
	return !(*this > d);
}

// !=运算符重载
bool Date::operator != (const Date& d)const
{
	return !(*this == d); // 复用
}


// << 运算符重载
//void Date::operator<<(ostream& out)
//{
//	out << _year << "-" << _month << "-" << _day << endl;
//}
