#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <list>

using namespace std;

void TestString1() //����
{
	string s1();  // �޲ι��� "\0"

	string s2("hello world!!!");  // ���ι��� "hello world!!!"
	// string s2 = "hello";  // OK��
	// "hello"������ʱ����������ʽ����ת��+�������Ż� (�����ƪ)
	cout << "s2: " << s2 << endl;

	string s3(s2); // ��������  "hello world!!!"
	cout << "s3: " << s3 << endl;

	string s4(s3, 6, 5); // ����ָ��λ�ÿ�ʼ�ͽ���  "world"
	// string s4(s3, 6); // ȱʡֵĬ�ϵ��ַ�����β "world!!!"
	cout << "s4: " << s4 << endl;

	string s5("hello", 2); // ����ǰn���� "he"
	cout << "s5: " << s5 << endl;

	string s6(10, 'x'); // ��n��x�����й����ʼ�� "xxxxxxxxxx"
	cout << "s6: " << s6 << endl;

}

void TestString2() // ��ֵ���������
{
	string s1;
	string s2 = "hello world!!";
	// ���� + �������� -->�������Ż� --> ֱ�ӹ���

	s1 = s2;
	s1 = "XXXX";  // ������
	s1 = 'y';   // ������
}

void TestString3() // []���������
{
	string s1 ("hello world!!");
	cout << s1[0] << endl;

	s1[0] = 'X';
	cout << s1 << endl;

	// Ҫ�����string��ÿ���ַ�+1
	for (size_t i = 0; i < s1.size(); ++i)
	{
		s1[i]++;
	}
	cout << s1 << endl;

	const string s2("world");
	for (size_t i = 0; i < s2.size(); ++i)
	{
		// s2[i]++; //err  const���಻���Ա��޸�
		cout << s2[i] << " ";  // ֻ��ӡ�����޸�
	}
	cout << endl;
	cout << s2 << endl;

	// ����[]��Խ��
	// s2[100]; // �ڲ�����Խ��
}

void TestString4()
{
	string s("hello");
	string::iterator it = s.begin(); // һ������it��begin()Ϊ��Ԫ�� ��λ��
	while (it != s.end()) // end()Ϊ���һ��Ԫ�� +1 ��λ��
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// �κ����͵� ������ ���������ǵ�����
	// vector<int>::iterator
	// list<int>::iterator
	// iterator ��ָ��һ�����ͣ��п��ܾ���ָ�룬
	// Ҳ�п��ܲ���ָ�룬���������÷���ָ��һ����


	// ��Χfor -- �Զ��������Զ��жϽ���
	// ����ȡs��ÿһ���ַ�����ֵ��ch
	/*for (auto ch : s)
	{
		// ++ch; // ch����ʱ������s���ᱻ�޸�
		cout << ch << " ";
	}
	cout << endl;*/

	for (auto& ch : s)
	{
		++ch; // �������ã�ch�� s�ı���
		cout << ch << " ";
	}
	cout << endl;
	cout << s << endl; // s���޸���


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

	//��Χfor�ĵײ㣬��ʵ���� ��������  
}

void PrintString(const string& str)
{
	// ���δ�const������const_iterator ������
	string::const_iterator it = str.begin();
	// auto it = str.begin();

	while (it != str.end())
	{
		// *it = 'X'; // err  const���ܱ��޸�
		cout << *it << " ";
		++it;
	}
	cout << endl;


	// ������
	string::const_reverse_iterator rit = str.rbegin();
	// auto rit =  str.rbegin(); 
	// �Զ�ƥ�䣬ͨ��rbegin()�ķ���ֵ �� ���εĲ����Ƿ��const ���жϡ�

	while (rit != str.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	// ��4�����͵ĵ�������
	// iterator / const_iterator  ���������2��
	// reverse_iterator / const_reverse_iterator  ���������2��
}

void TestString5()
{
	string s("hello");
	string::reverse_iterator rit = s.rbegin(); // ���������
	while (rit != s.rend())
	{
		cout << *rit << " "; // ���o l l e h
		++rit;
	}
	cout << endl;

	// ʹ��const_iterator�����������
	// 1������ʱ������const  2������󴴽�ʱ��const
	PrintString(s);
}

void TestString6()
{
	string s("hello");
	s.push_back('-');  // ���뵥���ַ�
	s.push_back('-');  
	s.append("world");  // �����ַ���
	cout << s << endl;

	string str("����˭");
	str += '@';   // string::operator+= ���������
	str += "BB";   // += �ַ����ַ�����string����
	s += str;   // += �ײ�Ҳ��push_back��append

	cout << s << endl;
	cout << str << endl << endl;


	// �õ�����+- �ܿ���ͷ�ͽ�β����
	// ������2��3��char��+-���ܻᵼ���ַ���ȡ����
	s.append(++str.begin(), --str.end()); 
	cout << s << endl;

	//string copy(++s.begin(), --s.end());
	string copy(s.begin() + 5, s.end() - 5); // С��Խ��
	cout << copy << endl;

}


void TestString7()
{
	//string s1;
	//string s2("11111111111111");
	//cout << s1.max_size() << endl; //û�����壬�����һ��
	//cout << s2.max_size() << endl;

	//cout << s1.capacity() << endl;
	//cout << s2.capacity() << endl;

	
	string s;
	// reverse ����
	s.reserve(1000); //���� ���ռ�
	//s.resize(1000, 'x');    //  ���ռ� + ��ʼ��
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


