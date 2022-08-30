#pragma once


//�����������
#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
	// ��Ԫ���� -- ��������ڲ�����ʹ�õ�ǰ�������˽�б�����Ա��
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
	// ȫȱʡ�Ĺ��캯��
	// ���캯����Ƶ�����ã�����ֱ�ӷ��������涨����Ϊinline
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;

		//if (!CheckDate())  // !this->CheckDate()
		//{
		//	Print();
		//	cout << "�չ�������ڷǷ�" << endl;
		//}

		assert(CheckDate()); // ��ֹ���ڷǷ�
	}

	// �������캯��
	// d2(d1)
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// ��ֵ���������
	// d1 = d3 -> d1.operator=(&d1, d3)
	Date& operator=(const Date& d)
	{
		if (this != &d) // �жϵ�ַ����ȣ��Ÿ�ֵ
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
		// �����thisָ����d1���������ǵ�ǰ���������˵�ǰ�����������١�
		// ��˿����� ���� �����ء�
	}

	// ��������
	~Date()
	{
		_year = 0;
		_month = 0;
		_day = 0;
		// û���ռ䣬��ʵ��д��������Ҳ�С�
	}


	// ��ȡĳ��ĳ�µ�����
	// ��Ƶ�����ã�����ֱ�ӷ��������涨����Ϊinline
	int GetMonthDay(int year, int month)
	{
		// Ƶ������ static �����ظ���������
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) //��������
		{
			day += 1; // ��������Ķ���
		}
		return day; // ���ص��µ�����
	}

	// ����+=����
	Date& operator+=(int day); 
	// ����+����
	Date operator+(int day)const;

	// ++d1; ��  d1++;
	// ֱ�Ӱ��������أ��޷�����
	// ���⴦��ʹ���������֣�����++��������һ��int������ǰ�ù��ɺ������ؽ�������
	
	// ǰ��++
	Date& operator++();
	// ����++
	Date operator++(int);
	// ����--
	Date operator--(int);
	// ǰ��--
	Date& operator--();
	// ����-����
	Date operator-(int day)const;
	// ����-=����
	Date& operator-=(int day);
	// ����-���� ��������
	int operator-(const Date& d)const;



	// >���������
	bool operator>(const Date& d)const;
	// ==���������
	bool operator==(const Date& d)const;
	// >=���������
	bool operator >= (const Date& d)const;
	// <���������
	bool operator < (const Date& d)const;
	// <=���������
	bool operator <= (const Date& d)const;
	// !=���������
	bool operator != (const Date& d)const;

	// ��� void Print(const Date* const this) 
	void Print()const
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	//// << ���������
	//void operator<<(ostream& out);

private:
	int _year;
	int _month;
	int _day;
};

// ������ << ��������� ȫ�� ����Ԫ��
// ��Ϊcout�����в�������Ϊ�����������������̶�Ϊthis�����Զ�����ȫ���С�
// ȫ�����޷��������е�˽�г�Ա��������Ҫ����Ԫ������ʵ�ַ���˽�С�
// ȫ������ + ��Ԫ������ʵ�֣� cout << d1;
// ������ֵ�� cout << d1 << d2; ����ʹ��
inline ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "��" << d._month << "��" << d._day << "��" << endl;
	return out;
}

// ����ȡ >> ��������� ȫ�� ����Ԫ��
// �� �� ����ȡ���ݵ� �� ��
inline istream& operator>>(istream& in, Date& d) 
{
	in >> d._year >> d._month >> d._day;
	assert(d.CheckDate()); // �ж������Ƿ�Ϸ�
	return in;
}

class Stack
{
};

//���졢�������졢��ֵ���ء�������Ĭ�����ɶ������á�
class MyQueue
{
private:
	Stack _st1;
	Stack _st2;
};


