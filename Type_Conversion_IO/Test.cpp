#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <fstream>      // std::ifstream

using namespace std;


//void Insert(size_t pos, char ch)
//{
//	size_t _size = 10;
//	int end = _size - 1;
//	while (end >= pos)    // end ��ʽ����ת��
//	{
//		// _str[end + 1] = _str[end];
//		--end;
//	}
//}
//
//void Test()
//{
//	int i = 1;
//	// ��ʽ����ת��(�������������)
//	double d = i;
//	printf("%d, %.2f\n", i, d);
//
//	int* p = &i;
//	// ��ʾ��ǿ������ת�������岻��������ͣ�ֵת���������壩
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
//	// ��֧��
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
//	virtual void f(){}  // �������Ҫ���麯��
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
//// A*��ָ���п���ָ���࣬�п���ָ������
//void func(A* pa)
//{
//	// dynamic_cast ���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�
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
//	// ���paָ�����࣬����ת���� ת�����ʽ������ȷ�ĵ�ַ
//	// ���paָ���࣬��ô����ת����ת�����ʽ����nullptr
//	
//	B* pb = dynamic_cast<B*>(pa);
//	if (pb)
//	{
//		cout << "ת���ɹ�" << endl;
//		pb->_a++;
//		pb->_b++;
//		cout << pb->_a << ":" << pb->_b << endl;
//	}
//	else
//	{
//		cout << "ת��ʧ��" << endl;
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
//	// �������������β�����ת��Ϊ����
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
//	const int a = 2;     // C++��const�Ǵ���ջ��
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
// fprintf/fscanf   // ����ļ�
// sprintf/sscanf   // ����ַ���

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


// ostream/istream ����֧���Զ������Ͷ���������������ȡ
// �Զ������ͣ������Լ����أ���������ȡ��������ķ�ʽ
//
//int main()
//{
//	/*int i = 1;
//	double j = 2.2;
//	cout << i << j << endl;*/
//
//	// 2022 11 28
//	// ������ֵ��Ĭ�϶����ÿո���߻��зָ�
//	int year, month, day;
//	//cin >> year >> month >> day;
//	//scanf("%d%d%d", &year, &month, &day);
//	//scanf("%d %d %d", &year, &month, &day); //����Ҫȥ�ӿո�
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


//// �ж��в�������
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
//		cout << year << "��" << month << "��" << day << "��" << endl;
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
//	// �������� ת�����Զ�������
//	A aa1 = 1; // ��ʽ����ת�� ��1����A��ʱ�����ٿ�������aa1���Ż���ֱ��1����aa1
//
//	// �Զ������� ת������������
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
//		// ����������д�ģ���������_yearΪ0�������
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
//// C++ IO����ʹ���������+��������صķ�ʽ
//// �ܸ��õļ����Զ������ͣ������������ȡ
//int main()
//{
//	// �Զ�ʶ�����͵ı���--��������
//	// �������Ϳ���ֱ��ʹ��--��Ϊ������ostream�����Ѿ�ʵ����
//	int i = 1;
//	double j = 2.2;
//	cout << i << endl;
//	cout << j << endl;
//	// �Զ�����������Ҫ�����Լ�����<< �� >>
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
		// ����������д�ģ���������_yearΪ0�������
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
//	while (ifs)    // ��ʽ����ת��bool������iosʵ�ֵģ�fstream�̳�
//	{
//		cout << ch;
//		ch = ifs.get();
//	}
//
//	// �����������Զ�close
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