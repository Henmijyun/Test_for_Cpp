#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

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
}

int main()
{
	//TestString1();
	//TestString2();
	//TestString3();
	TestString4();
	return 0;
}


