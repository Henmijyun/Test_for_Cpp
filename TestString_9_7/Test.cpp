#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

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
}

int main()
{
	//TestString1();
	//TestString2();
	//TestString3();
	TestString4();
	return 0;
}


