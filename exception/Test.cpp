
#include <iostream>
#include <string>
#include <stack>
#include <time.h>
#include <windows.h>

using namespace std;

//double Division(int a, int b)
//{
//	// ��b==0ʱ�����쳣
//	if (b == 0)
//		throw"Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//
//void Func()
//{
//	try
//	{
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (int errid)
//	{
//		cout << errid << endl;
//	}
//	/*catch (const char* errmsg)  // λ����� �� ����ƥ��
//	{
//		cout << errmsg << endl;
//	}*/
//
//	cout << "Func() end" << endl;
//}
//
//int main()
//{
//	while (1)
//	{
//		try
//		{
//			Func();
//		}
//		catch (int errid)
//		{
//			cout << errid << endl;
//		}
//		catch (const char* errmsg)
//		{
//			cout << errmsg << endl;
//		}
//		catch (...) // �����������͵��쳣 -- ��ֹ����δ�����쳣ʱ��������ֹ
//		{
//			cout << "δ֪�쳣" << endl;
//		}
//	}
//
//	return 0;
//}




//class Exception // ���쳣ʱ���ض��󣬿��Է����������ֵ
//{
//public:
//	Exception(const string& errmsg, int id)
//		:_errmsg(errmsg)
//		, _errid(id)
//	{}
//
//	virtual string what() const
//	{
//		return _errmsg;
//	}
//
//	int GetErrid() const
//	{
//		return _errid;
//	}
//
//protected:
//	string _errmsg;  
//	int _errid;
//};
//
//double Division(int a, int b)
//{
//	// ��b == 0ʱ�׳��쳣
//	if (b == 0)
//	{
//		Exception e("��0����", 1);  // ���������
//		throw e;   // ��ֵ���Σ��������ʱ���󿽱����������ƶ���������
//	}
//	else
//	{
//		return ((double)a / (double)b);
//	}
//}
//
//void Func1()
//{
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//}
//
//
//// 1�����쳣�������������Ͷ���
//// 2������ʱ��Ҫ������ƥ��
//int main()
//{
//	while (1)
//	{
//		try
//		{
//			Func1();
//		}
//		catch (const Exception& e)
//		{
//			cout << e.what() << endl;
//			cout << e.GetErrid() << endl;
//		}
//		catch (...) // �����������͵��쳣 -- ��ֹ����δ�����쳣ʱ��������ֹ
//		{
//			cout << "δ֪�쳣" << endl;
//		}
//	}
//
//	return 0;
//}








//class Exception // ����
//{
//public:
//	Exception(const string& errmsg, int id)
//		:_errmsg(errmsg)
//		, _errid(id)
//	{}
//
//	virtual string what() const
//	{
//		return _errmsg;
//	}
//
//	int getid() const
//	{
//		return _errid;
//	}
//
//protected:
//	string _errmsg; // ������Ϣ
//	int _errid;     // ������
//};
//
//class SqlException : public Exception  // ������ �����ݿ⣩
//{
//public:
//	SqlException(const string& errmsg, int errid, const string& sql)
//		:Exception(errmsg, errid)  // ��������Ҫ���ø���Ĺ��캯��
//		, _sql(sql)
//	{}
//
//	virtual string what() const  // �麯������д
//	{
//		string str = "SqlException:";
//		str += _errmsg;
//		str += "->";
//		str += _sql;
//
//		return str;
//	}
//protected:
//	const string _sql;
//};
//
//class HttpServerException : public Exception  // ������ ���������
//{
//public:
//	HttpServerException(const string& errmsg, int id, const string& type)
//		:Exception(errmsg, id)
//		, _type(type)
//	{}
//	virtual string what() const
//	{
//		string str = "HttpServerException:";
//		str += _type;
//		str += ":";
//		str += _errmsg;
//		return str;
//	}
//private:
//	const string _type;
//};
//
//class CacheException : public Exception  // �����ࣨ���棩
//{
//public:
//	CacheException(const string& errmsg, int errid)
//		:Exception(errmsg, errid)
//	{}
//
//	virtual string what() const
//	{
//		string str = "CacheException:";
//		str += _errmsg;
//		return str;
//	}
//
//protected:
//	// stack<string> _stPath;  
//	// ������������ ��ջ�еĺ������� תΪ�ַ����⻯���������쳣 ����֪���庯������
//};
//
//void SQLMgr()
//{
//	srand(time(0));
//	if (rand() % 7 == 0)
//	{
//		throw SqlException("Ȩ�޲���", 100, "select * from name = '����'");
//	}
//	//throw "xxxxxx";
//
//	cout << "��������ɹ�" << endl;
//}
//
//void CacheMgr()
//{
//	srand(time(0));
//	if (rand() % 5 == 0)
//	{
//		throw CacheException("Ȩ�޲���", 100);
//	}
//	else if (rand() % 6 == 0)
//	{
//		throw CacheException("���ݲ�����", 101);
//	}
//	SQLMgr();
//}
//
//void HttpServer()
//{
//	// ģ���������
//	srand(time(0));
//	if (rand() % 3 == 0)
//	{
//		throw HttpServerException("������Դ������", 100, "get");
//	}
//	else if (rand() % 4 == 0)
//	{
//		throw HttpServerException("Ȩ�޲���", 101, "post");
//	}
//	CacheMgr();
//}
//
//int main()
//{
//	while (1)
//	{
//		//this_thread::sleep_for(chrono::seconds(1));
//		Sleep(1000);
//
//		try 
//		{
//			HttpServer();
//		}
//		catch (const Exception& e) // ���ﲶ�������Ϳ���
//		{
//			// ��̬
//			cout << e.what() << endl;
//			// �׳�����what�ǽ��й���д���ģ���д���ĸ�ʱ���쳣���ͻ������һ��
//		}
//		catch (...)
//		{
//			cout << "Unkown Exception" << endl;
//		}
//	}
//	return 0;
//}



class Exception // ����
{
public:
	Exception(const string& errmsg, int id)
		:_errmsg(errmsg)
		, _errid(id)
	{}

	virtual string what() const
	{
		return _errmsg;
	}

	int getid() const
	{
		return _errid;
	}

protected:
	string _errmsg; // ������Ϣ
	int _errid;     // ������
};

class HttpServerException : public Exception  // ������ ���������
{
public:
	HttpServerException(const string& errmsg, int id, const string& type)
		:Exception(errmsg, id)
		, _type(type)
	{}
	virtual string what() const
	{
		string str = "HttpServerException:";
		str += _type;
		str += ":";
		str += _errmsg;
		return str;
	}
private:
	const string _type;
};

void SeedMsg(const string& str)
{
	// Ҫ����������������3��
	srand(time(0));
	
	if (rand() % 3 == 0)
	{
		throw HttpServerException("������Դ������", 100, "get");
	}
	else if (rand() % 4 == 0)
	{
		throw HttpServerException("Ȩ�޲���", 101, "post");
	}

	cout << "���ͳɹ�:"<< str << endl;

}
void HttpServer()
{
	// Ҫ����������������3��
	string str;
	cin >> str;
	int n = 3;
	try
	{
		SeedMsg(str);
	}
	catch (const Exception& e)
	{
		if (e.getid() == 100 && n)
		{
			SeedMsg(str);
			n--;
		}

		throw e; // �����׳�
	}
}
int main()
{
	while (1)
	{
		//this_thread::sleep_for(chrono::seconds(1));
		Sleep(1000);

		try
		{
			HttpServer();
		}
		catch (const Exception& e) // ���ﲶ�������Ϳ���
		{
			// ��̬
			cout << e.what() << endl;
			// �׳�����what�ǽ��й���д���ģ���д���ĸ�ʱ���쳣���ͻ������һ��
		}
		catch (...)
		{
			cout << "Unkown Exception" << endl;
		}
	}
	return 0;
}

