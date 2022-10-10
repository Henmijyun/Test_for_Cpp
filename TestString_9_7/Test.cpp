#define _CRT_SECURE_NO_WARNINGS 1
#include "MyString.h"

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

// 例题：字符串相加
//class Solution {
//public:
//	string addStrings(string num1, string num2) {
//		int end1 = num1.size() - 1, end2 = num2.size() - 1;
//		int next = 0;
//		string strRet;  // 保存结果
//		while (end1 >= 0 || end2 >= 0)
//		{
//			int val1 = end1 >= 0 ? num1[end1] - '0' : 0;  // 减字符零-'0' 把字符->数字，保存到val1
//			int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
//			int ret = val1 + val2 + next;
//			next = ret > 9 ? 1 : 0;
//
//			strRet += (ret % 10) + '0';  // 利用 += 运算符重载，尾插字符 （数字->字符 +'0'）
//
//			--end1;  // 从后往前走
//			--end2;
//		}
//		if (1 == next)
//			strRet += '1';
//
//		// 尾插完了之后， 逆序
//		reverse(strRet.begin(), strRet.end());
//
//		return strRet;
//	}
//};

void TestString8()
{
	string str("wo lai le");
	/*for (size_t i = 0; i < str.size(); ++i)
	{
		if (' ' == str[i])
		{ 
			str.insert(i, "20%");
			i += 3;
		}
	}
	cout << str << endl;


	for (size_t i = 0; i < str.size(); ++i)
	{
		if (' ' == str[i])
		{
			str.erase(i, 1);
		}
	}
	cout << str << endl;*/

	// 以空间换时间
	string newstr;
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (' ' != str[i])
		{
			newstr += str[i];
		}
		else
		{
			newstr += "20%";
		}
	}
	cout << newstr << endl;

}
void TestString9()
{
	// 把文件内容 读取到 控制台面板
	string filename("Test.cpp");
	FILE* fout = fopen(filename.c_str(), "r"); //以C的形式返回字符串
	assert(fout);
	char ch = fgetc(fout);
	while (ch != EOF) 
	{
		cout << ch;
		ch = fgetc(fout);
	}
}

void TestString10()
{
	string filename("Test.cpp");
	cout << filename << endl;
	cout << filename.c_str() << endl;  // 表面看起来没区别

	filename += '\0';  // 但是特殊情况下，就出问题了
	filename += "string.cpp";
	cout << filename << endl;  // string 对象按size为准
	cout << filename.c_str() << endl;  // 常量字符串对象\0结尾
 
	cout << filename.size() << endl;
	string copy = filename;
	cout << copy << endl << endl;

	for (unsigned char ch = 0; ch < 128; ++ch)
	{
		cout << ch; // 控制台打印ASCII表
	}
	cout << "\0" << endl; // 无法打印
}


void DealUrl(const string& url)
{
	size_t pos1 = url.find("://");  // find()查找://   pos1指向：
	if (pos1 == string::npos)
	{
		// 如果到最后都没有://，说明是非法链接
		cout << "非法url" << endl;
		return;
	}  

	string protocol = url.substr(0, pos1);  // pos1 为 5 ，所以截取下标0到4
	cout << protocol << endl;  // https

	size_t pos2 = url.find('/', pos1 + 3); 
	if (pos2 == string::npos)
	{
		cout << "非法url" << endl;
		return;
	}
	string domain = url.substr(pos1 + 3, pos2 - pos1 - 3);
	cout << domain << endl;

	string uri = url.substr(pos2 + 1);
	cout << uri << endl << endl;
}

void TestString11()
{
	string filename("Test.cpp.tar.rar");
	// 找后缀 -> find
	// size_t pos = filename.find('.');  // .cpp.tar.rar 第一个.开始的全部
	size_t pos = filename.rfind('.'); // .rar 查找到字符串中，最后一个出现的内容（逆方向查找）
	if (pos != string::npos)
	{
		//string suff = filename.substr(pos, filename.size() - pos); // ok
		string suff = filename.substr(pos); // 可以缺省，两种都行
		cout << suff << endl;
	}

	string url1 = "https://cplusplus.com/reference/string/string/";
	string url2 = "https://image.baidu.com/search/detail?ct=503316480&z=0&ipn=d&word=ascall&step_word=&hs=0&pn=0&spn=0&di=7108135681917976577&pi=0&rn=1&tn=baiduimagedetail&is=0%2C0&istype=0&ie=utf-8&oe=utf-8&in=&cl=2&lm=-1&st=undefined&cs=2613959014%2C543572025&os=2740573600%2C1059518451&simid=2613959014%2C543572025&adpicid=0&lpn=0&ln=179&fr=&fmq=1660115697093_R&fm=&ic=undefined&s=undefined&hd=undefined&latest=undefined&copyright=undefined&se=&sme=&tab=0&width=undefined&height=undefined&face=undefined&ist=&jit=&cg=&bdtype=0&oriquery=&objurl=https%3A%2F%2Fgimg2.baidu.com%2Fimage_search%2Fsrc%3Dhttp%3A%2F%2Fimg.php.cn%2Fupload%2Fimage%2F147%2F157%2F796%2F1593765739620093.png%26refer%3Dhttp%3A%2F%2Fimg.php.cn%26app%3D2002%26size%3Df9999%2C10000%26q%3Da80%26n%3D0%26g%3D0n%26fmt%3Dauto%3Fsec%3D1662707704%26t%3Da68cb238bbb3f99d0554098c785d526e&fromurl=ippr_z2C%24qAzdH3FAzdH3Fooo_z%26e3Brir_z%26e3BvgAzdH3FuwqAzdH3F9c9amd_z%26e3Bip4s&gsm=1&rpstart=0&rpnum=0&islist=&querylist=&nojc=undefined&dyTabStr=MCwzLDIsNCw2LDEsNSw3LDgsOQ%3D%3D";
	string url3 = "ftp://ftp.cs.umd.edu/pub/skipLists/skiplists.pdf";

	DealUrl(url1);
	DealUrl(url2);
	DealUrl(url3);
}


//int main()
//{
//	//TestString1();
//	//TestString2();
//	//TestString3();
//	//TestString4();
//	//TestString5();
//	//TestString6();
//	//TestString7();
//	//TestString8();
//	//TestString9();
//	//TestString10();
//	TestString11();
//	string s1("hello");
//	string s2;
//	
//	cout << s1.c_str() << endl;  // c_str()返回c形式的字符串char*
//	cout << s2.c_str() << endl;
//	
//	for (auto ch : s1)
//	{
//		cout << ch << ' ';
//	}
//	cout << endl;
//
//	return 0;
//}

#include "MyString.h"

int main()
{
	try
	{
		//skk::TestString1();
		skk::TestString2();
	}
	catch (const exception& e) // 抛异常处理
	{
		cout << e.what() << endl;  
	}
	
	return 0;
}


