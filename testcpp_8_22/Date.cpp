#define _CRT_SECURE_NO_WARNINGS 1

//������Ķ���
#include "Date.h"



// ����+=����
Date& Date::operator+=(int day) // ����ֵ��&���ã������ɿ�����Ҳ������������������಻������
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
	return *this; // ��Ϊthisָ���࣬��������õ���
}

// ����+����
Date Date::operator+(int day)const
{
	Date ret(*this); // Ϊ�˲�Ӱ��ǰһ�����ֵ������һ�����������
	// ������ǳ�����������������������Ρ�

	// ����
	ret += day;

	return ret; // �������������������
}

// ǰ��++
Date& Date::operator++()
{
	return *this += 1;
}

// ����++
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;

	return tmp;
}



// ǰ��--
Date& Date::operator--()
{
	return *this -= 1;
}

// ����--
Date Date::operator--(int)
{
	Date tmp(*this); // ��������
	*this -= 1;
	return tmp;  // ��ֵ��������һ�ο���
}

// ����-���� ��������
int Date::operator-(const Date& d)const
{
	int flag = 1;   // ���Ʒ���ֵ��������
	Date max = *this;  // Ĭ��*this����Ϊ��
	Date min = d;
	if (*this < d)  // �������
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int n = 0;
	while (min != max)
	{
		++min;
		++n;  // ��¼����
	}
	return flag * n;
}

// ����-���� 
Date Date::operator-(int day)const
{
	Date ret = *this;
	ret -= day;
	return ret;
}

// ����-=����
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



// >���������  d1 > d2
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

// ==���������
bool Date::operator==(const Date& d)const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

// >=���������
bool Date::operator >= (const Date& d)const
{
	return (*this > d) || (*this == d);
}

// <���������
bool Date::operator < (const Date& d)const
{
	return !(*this >= d);
}

// <=���������
bool Date::operator <= (const Date& d)const
{
	return !(*this > d);
}

// !=���������
bool Date::operator != (const Date& d)const
{
	return !(*this == d); // ����
}


// << ���������
//void Date::operator<<(ostream& out)
//{
//	out << _year << "-" << _month << "-" << _day << endl;
//}
