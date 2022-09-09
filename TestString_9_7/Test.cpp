#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <list>

using namespace std;

void TestString1() //构造
{
	string s1();  // 无参构造 "\0"

	string s2("hello world!!!");  // 带参构造 "hello world!!!"
	// string s2 = "hello";  // OK，
	// "hello"生成临时拷贝，再隐式类型转换+编译器优化 (类的下篇)
	cout << "s2: " << s2 << endl;

	string s3(s2); // 拷贝构造  "hello world!!!"
	cout << "s3: " << s3 << endl;

	string s4(s3, 6, 5); // 拷贝指定位置开始和结束  "world"
	// string s4(s3, 6); // 缺省值默认到字符串结尾 "world!!!"
	cout << "s4: " << s4 << endl;

	string s5("hello", 2); // 拷贝前n个数 "he"
	cout << "s5: " << s5 << endl;

	string s6(10, 'x'); // 用n个x，进行构造初始化 "xxxxxxxxxx"
	cout << "s6: " << s6 << endl;

}

void TestString2() // 赋值运算符重载
{
	string s1;
	string s2 = "hello world!!";
	// 构造 + 拷贝构造 -->编译器优化 --> 直接构造

	s1 = s2;
	s1 = "XXXX";  // 很少用
	s1 = 'y';   // 很少有
}

void TestString3() // []运算符重载
{
	string s1 ("hello world!!");
	cout << s1[0] << endl;

	s1[0] = 'X';
	cout << s1 << endl;

	// 要求遍历string，每个字符+1
	for (size_t i = 0; i < s1.size(); ++i)
	{
		s1[i]++;
	}
	cout << s1 << endl;

	const string s2("world");
	for (size_t i = 0; i < s2.size(); ++i)
	{
		// s2[i]++; //err  const的类不可以被修改
		cout << s2[i] << " ";  // 只打印，不修改
	}
	cout << endl;
	cout << s2 << endl;

	// 关于[]的越界
	// s2[100]; // 内部会检查越界
}

void TestString4()
{
	string s("hello");
	string::iterator it = s.begin(); // 一般命名it，begin()为首元素 的位置
	while (it != s.end()) // end()为最后一个元素 +1 的位置
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 任何类型的 迭代器 都属于他们的类域
	// vector<int>::iterator
	// list<int>::iterator
	// iterator 像指针一样类型，有可能就是指针，
	// 也有可能不是指针，但是他的用法像指针一样。


	// 范围for -- 自动迭代，自动判断结束
	// 依次取s中每一个字符，赋值给ch
	/*for (auto ch : s)
	{
		// ++ch; // ch是临时拷贝，s不会被修改
		cout << ch << " ";
	}
	cout << endl;*/

	for (auto& ch : s)
	{
		++ch; // 加了引用，ch是 s的别名
		cout << ch << " ";
	}
	cout << endl;
	cout << s << endl; // s被修改了


	list<int> lt(10, 1);
	list<int>::iterator lit = lt.begin();
	while (lit != lt.end())
	{
		cout << *lit << " ";
		++lit;
	}
	cout << endl;

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	//范围for的底层，其实就是 迭代器。  
}

void PrintString(const string& str)
{
	// 传参带const所以用const_iterator （正向）
	string::const_iterator it = str.begin();
	// auto it = str.begin();

	while (it != str.end())
	{
		// *it = 'X'; // err  const不能被修改
		cout << *it << " ";
		++it;
	}
	cout << endl;


	// （反向）
	string::const_reverse_iterator rit = str.rbegin();
	// auto rit =  str.rbegin(); 
	// 自动匹配，通过rbegin()的返回值 和 传参的参数是否带const 来判断。

	while (rit != str.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	// 共4种类型的迭代器：
	// iterator / const_iterator  正向迭代器2种
	// reverse_iterator / const_reverse_iterator  反向迭代器2种
}

void TestString5()
{
	string s("hello");
	string::reverse_iterator rit = s.rbegin(); // 反向迭代器
	while (rit != s.rend())
	{
		cout << *rit << " "; // 输出o l l e h
		++rit;
	}
	cout << endl;

	// 使用const_iterator的两种情况：
	// 1、传参时参数加const  2、类对象创建时带const
	PrintString(s);
}

void TestString6()
{
	string s("hello");
	s.push_back('-');  // 插入单个字符
	s.push_back('-');  
	s.append("world");  // 插入字符串
	cout << s << endl;

	string str("我是谁");
	str += '@';   // string::operator+= 运算符重载
	str += "BB";   // += 字符、字符串、string对象
	s += str;   // += 底层也是push_back、append

	cout << s << endl;
	cout << str << endl << endl;


	// 用迭代器+- 避开开头和结尾的数
	// 中文是2、3个char，+-可能会导致字符读取出错
	s.append(++str.begin(), --str.end()); 
	cout << s << endl;

	//string copy(++s.begin(), --s.end());
	string copy(s.begin() + 5, s.end() - 5); // 小心越界
	cout << copy << endl;

}


void TestString7()
{
	//string s1;
	//string s2("11111111111111");
	//cout << s1.max_size() << endl; //没有意义，输出都一样
	//cout << s2.max_size() << endl;

	//cout << s1.capacity() << endl;
	//cout << s2.capacity() << endl;

	
	string s;
	// reverse 逆置
	s.reserve(1000); //保留 开空间
	//s.resize(1000, 'x');    //  开空间 + 初始化
	size_t sz = s.capacity();
	sz = s.capacity();
	cout << "capacity changed: " << sz << '\n';
	cout << "making s grow:\n";
	for (int i = 0; i < 1000; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

int main()
{
	//TestString1();
	//TestString2();
	//TestString3();
	//TestString4();
	//TestString5();
	//TestString6();
	TestString7();
	return 0;
}


