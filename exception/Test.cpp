
#include <iostream>
#include <string>
#include <stack>
#include <time.h>
#include <windows.h>

using namespace std;

//double Division(int a, int b)
//{
//	// 当b==0时，抛异常
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
//	/*catch (const char* errmsg)  // 位置最近 且 类型匹配
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
//		catch (...) // 捕获任意类型的异常 -- 防止出现未捕获异常时，程序终止
//		{
//			cout << "未知异常" << endl;
//		}
//	}
//
//	return 0;
//}




//class Exception // 抛异常时返回对象，可以反馈多个参数值
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
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		Exception e("除0错误", 1);  // 传多个参数
//		throw e;   // 传值传参，会产生临时对象拷贝（可以用移动构造解决）
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
//// 1、抛异常可以抛任意类型对象
//// 2、捕获时，要求类型匹配
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
//		catch (...) // 捕获任意类型的异常 -- 防止出现未捕获异常时，程序终止
//		{
//			cout << "未知异常" << endl;
//		}
//	}
//
//	return 0;
//}








//class Exception // 基类
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
//	string _errmsg; // 错误信息
//	int _errid;     // 错误码
//};
//
//class SqlException : public Exception  // 派生类 （数据库）
//{
//public:
//	SqlException(const string& errmsg, int errid, const string& sql)
//		:Exception(errmsg, errid)  // 派生类需要调用父类的构造函数
//		, _sql(sql)
//	{}
//
//	virtual string what() const  // 虚函数的重写
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
//class HttpServerException : public Exception  // 派生类 （网络服务）
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
//class CacheException : public Exception  // 派生类（缓存）
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
//	// 来利用容器把 堆栈中的函数调用 转为字符虚拟化出来，抛异常 （可知具体函数出错）
//};
//
//void SQLMgr()
//{
//	srand(time(0));
//	if (rand() % 7 == 0)
//	{
//		throw SqlException("权限不足", 100, "select * from name = '张三'");
//	}
//	//throw "xxxxxx";
//
//	cout << "本次请求成功" << endl;
//}
//
//void CacheMgr()
//{
//	srand(time(0));
//	if (rand() % 5 == 0)
//	{
//		throw CacheException("权限不足", 100);
//	}
//	else if (rand() % 6 == 0)
//	{
//		throw CacheException("数据不存在", 101);
//	}
//	SQLMgr();
//}
//
//void HttpServer()
//{
//	// 模拟网络服务
//	srand(time(0));
//	if (rand() % 3 == 0)
//	{
//		throw HttpServerException("请求资源不存在", 100, "get");
//	}
//	else if (rand() % 4 == 0)
//	{
//		throw HttpServerException("权限不足", 101, "post");
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
//		catch (const Exception& e) // 这里捕获父类对象就可以
//		{
//			// 多态
//			cout << e.what() << endl;
//			// 抛出来的what是进行过重写过的，重写到哪个时抛异常，就会读到那一个
//		}
//		catch (...)
//		{
//			cout << "Unkown Exception" << endl;
//		}
//	}
//	return 0;
//}






//class Exception // 基类
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
//	string _errmsg; // 错误信息
//	int _errid;     // 错误码
//};
//
//class HttpServerException : public Exception  // 派生类 （网络服务）
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
//void SeedMsg(const string& str)
//{
//	// 要求出现网络错误重试3次
//	srand(time(0));
//	
//	if (rand() % 3 == 0)
//	{
//		throw HttpServerException("网络错误", 100, "get");
//	}
//	else if (rand() % 4 == 0)
//	{
//		throw HttpServerException("权限不足", 101, "post");
//	}
//
//	cout << "发送成功:"<< str << endl;
//
//}
//void HttpServer()
//{
//	// 要求出现网络错误重试3次
//	string str = "今晚一起看电影怎么样？";
//	//cin >> str;
//	int n = 3;
//	while (n--)
//	{
//		try
//		{
//			SeedMsg(str);
//
//			break;   // 没有异常，跳出循环
//		}
//		catch (const Exception& e)
//		{
//			// 网络错误 且 重试3次
//			if (e.getid() == 100 && n > 0)
//			{
//				continue; // 重试
//			}
//			else
//			{
//				throw e; // 重新抛出
//			}		
//		}
//	}
//
//
//}
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
//		catch (const Exception& e) // 这里捕获父类对象就可以
//		{
//			// 多态
//			cout << e.what() << endl;
//			// 抛出来的what是进行过重写过的，重写到哪个时抛异常，就会读到那一个
//
//			// ...记录日志
//		}
//		catch (...)
//		{
//			cout << "Unkown Exception" << endl;
//		}
//	}
//	return 0;
//}



double Division(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}

void Func()
{
	// 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再
	// 重新抛出去。
	
	// 隐患，第一个new成功，第二个new失败抛异常，导致第一个创建的内存泄露
	// 可以解决，但是很麻烦，这样的问题一般是用智能指针解决
	int* array1 = new int[10];
	int* array2 = new int[10];  //隐患
	try 
	{
		// int* array2 = new int[10];  //写在这里勉强解决隐患，但是可读性差
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)    // 这里必须接收，为了释放内存
	{
		cout << "delete []" << array1 << endl;
		delete[] array1;

		cout << "delete []" << array2 << endl;
		delete[] array2;

		throw;  // 捕获什么就抛出什么
	}
	// ...
	cout << "delete []" << array1 << endl;
	delete[] array1;

	cout << "delete []" << array2 << endl;
	delete[] array2;
}

int main()
{
	try
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	return 0;
}