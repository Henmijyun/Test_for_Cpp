//#define _CRT_SECURE_NO_WARNINGS 1

//#include <iostream>
//#include <vector>
// ��׼��Ķ������ŵ�std
//using namespace std;
// 1����Ŀ�У�������Ҫ using namespace std;
// 2���ճ���ϰ�� using namespace std;
// 3����Ŀ��ָ�������ռ���� + չ������

//namespace bit
//{
//	int rand = 0;
//}
//
//using namespace bit; 
////using �������ռ����չ��������ȫ�ֵı���һ���������Ƽ���
////�ŵ� namespace ����Ϊ�˱����ͻ�������� using չ���Ļ����ͳ�ͻ�ˡ�
////���Բ�����չ��
//int main()
//{
//	//printf("%d\n", rand); 
//	printf("%d\n", bit::rand); 
//	//���ھֲ��ң��ٵ�ȫ�����ң�ȫ�������������⺯�����Զ����int��
//	//Ϊ�˱����ͻ�����������ռ�bit
//	return 0;
//}
//
//using std::cout; //չ������
//using std::endl;
//int main()
//{
//	//��Ŀ�У�
//	std::vector<int> v; //ָ�������ռ����
//	v.push_back(1); //ֻ��Ҫǰ��ָ��һ�Σ�����Ϳ���ֱ������
//	v.push_back(2);
//
//	std::cout << "hello bit" << std::endl; //usingչ������ǰ
//	cout << "hello bit" << endl; //usingչ�����ú�
//
//
//	return 0;
//}

//
////�����ռ�Ķ��壺
////test.cpp
//namespace N1
//{
//	int a; //�������
//	int b;
//
//	int Add(int left, int right) //���庯��
//	{
//		return left + right;
//	}
//
//	struct Node //��������
//	{
//		struct Node* next;
//		int val;
//	};
//
//	namespace N2 //Ƕ��
//	{
//		int c;
//		int d;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
//// ps��һ�������е�test.h������test.cpp������N1�ᱻ�ϲ���һ����
////test.h
//namespace N1
//{
//	int Mul(int left, int right)
//	{
//		return left * right;
//	}
//}



//#include <iostream>
//using namespace std;
//// IO ��
//int main()
//{
//	//�ص㣺�Զ�ʶ������ ��%d%lf��
//	int i;
//	double d;
//
//	// >> ����ȡ
//	cin >> i >> d;
//
//	// << ������
//	cout << i << endl; //endl == '\n'
//	cout << d << endl;
//	cout << "hello world" << endl;
//	return 0;
//}



//#include <iostream>
//#include "Stack.h"
//using namespace std;
////ȱʡ����
//void Func(int a = 0)
//{
//	cout << a << endl;
//}
////ȫȱʡ
//void TextFunc1(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
////��ȱʡ
////���������������ȱʡ�����ܼ��
////����������У�ֻ����ȱʡc����b�����a
//void TextFunc2(int a, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//
//
//
//
//
//int main()
//{
//	struct Stack st1;
//	StackInit(&st1, 100); 
//	//֪��һ����100������Ҫ���룬ֱ�Ӵ���100
//	//��ǰ��100�Ŀռ䣬�������ݣ����Ч��
//
//	struct Stack st2;
//	StackInit(&st2); 
//	//��֪���������ݣ��Ͳ��趨����ʼĬ��Ϊ4��
//
//
//	Func(111);
//	Func();
//
//	TextFunc1();
//	TextFunc1(4); //�������Ҹ�
//	TextFunc1(4,5);
//	//TextFunc1(,,6); //��֧��
//	TextFunc1(4, 5, 6);
//
//
//	TextFunc2(7); 
//	TextFunc2(7, 8);
//	TextFunc2(7, 8, 9);
//	return 0;
//}
//

#include "Stack.h"

////C���Բ�����ͬ���������ڣ�����C++����
//int Add(int left, int right)
//{
//	return left + right;
//}
//
//double Add(double left, double right) //�������Ͳ�ͬ
//{
//	return left + right;
//}
//
//void func(int i, char ch)
//{
//	cout << "void func(int i, char ch)" << endl;
//}
//void func(char ch, int i) //��������˳��ͬ
//{
//	cout << "void func(char ch, int i)" << endl;
//}
//
//void func1(int i)
//{}
//
//int func1(int i) //��ͬ�������ķ���ֵ����ͬʱ�����������أ�����ʱҲ�޷�����
//{}
//
//int main()
//{
//	cout << Add(1, 2) << endl;
//	cout << Add(1.1, 2.2) << endl;
//
//	func(1, 'a');
//	func('a', 1);
//	return 0;
//}




//int main()
//{
//	int a = 0;
//	//int& b;   //1. �����ڶ���ʱ�����ʼ��
//
//	int& c = a;
//	int& d = a;
//	int& e = c; //2. һ�����������ж������
//
//	int x = 10;
//	//3. ����һ������һ��ʵ�壬�ٲ�����������ʵ��
//	c = x; // c��x�ı���������x��ֵ��c�� 
//
//	return 0;
//}


////1�������� ���� a������Ͳ���
//void Swap(int& r1, int& r2)
//{
//	//�������õĻ���r1��r2��a��b�ľֲ���ʱ��������Ӱ��a��b
//	//�������õĻ���r1��r2���޸Ļ�ֱ��Ӱ��a��b
//	int tmp = r1;
//	r1 = r2;
//	r2 = tmp;
//}
//
//typedef struct SeqList
//{
//	//...
//}SL;
//
//
//void SLPushBack(SL& s, int x) 
//{}//�൱�������ô���ָ�룬�ú����ڲ��ı�Ҳ���Ըı������ֵ
//
//
//typedef struct SListNode //������
//{
//	//..
//}SLTNode,*PSLTNode; //�Ե������ָ����������ں���Ĳ�����ʹ��&���ã�ʹ�䲻�ö���ָ�루���������ӣ�
//
//typedef struct SListNode* PSLTNode;
//
////void SListPushBack(SLTNode*& phead, int x)
//void SListPushBack(PSLTNode& phead, int x)
//{
//	if (phead == NULL)
//	{
//		phead = (SLTNode*)malloc(sizeof(SLTNode));
//		//...
//	}
//}
//int main()
//{
//	int a = 0, b = 2;
//	Swap(a, b);
//
//	SL sl;
//	SLPushBack(sl, 1);//�����Ļ��Ϳ��� ���ô���ַ &sl
//	SLPushBack(sl, 2);
//	SLPushBack(sl, 3);
//
//	SLTNode* list = NULL;
//	SListPushBack(list, 1);//Ϊ�˵�������Բ�������ָ�루������⣩
//	SListPushBack(list, 2);
//	SListPushBack(list, 3);
//
//	return 0;
//}


//#include <time.h>
//struct A { int a[10000]; };
//void TestFunc1(A aa) {}
//void TestFunc2(A& aa) {}
//
//void TestRefAndValue()
//{
//	A a;
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock(); //��¼����ǰ��ʱ��
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock(); //��¼������ʱ��
//
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//
//	// �ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl; //ǰ��ʱ��������õ�������ʱ
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//int main()
//{
//	TestRefAndValue();
//	return 0;
//}




//int Count1() //����&���õĻ�����ֵ����
//{
//	static int n = 0;
//	n++;
//	//...
//	return n; //����ֵ��n����ʱ����������n����
//}
//
//int& Count2()
//{
//	static int n = 0; //�����n�ǽ�����ջ�ľ�̬����ģ����Բ�������
//	n++;
//	//...
//	return n; //���������õķ�ʽ��ʡȥ�˿����Ĺ��̣�������Ч��
//}
//
//int main()
//{
//	int ret1 = Count1();
//	int& ret2 = Count2(); //ret2Ҳ��n�����ñ�����ֱ�ӷ��ʾ�̬���е�n
//
//	return 0;
//}
//


//int main()
//{
//	SL sl;
//	SLInit(sl);
//	SLPushBack(sl, 1);
//	SLPushBack(sl, 2);
//	SLPushBack(sl, 3);
//	SLPushBack(sl, 4);
//
//	for (int i = 0; i < sl._size; ++i)
//	{
//		cout << SLAt(sl, i) << " ";
//	}
//	cout << endl;
//
//	SLAt(sl, 3)++;
//	SLAt(sl, 0) = 10;
//
//	for (int i = 0; i < sl._size; ++i)
//	{
//		cout << SLAt(sl, i) << " ";
//	}
//	cout << endl;
//
//	return 0;
//}


//
//int main()
//{
//	int a = 10;
//	int& b = a; //Ȩ�޵�ƽ��
//	
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//
//	
//	const int c = 100;
//	//int& d = c;  //err//Ȩ�޲��ܷŴ�
//	const int& d = c; //Ȩ�޵�ƽ��
//
//	int e = 30;//�ɶ���д
//	const int& f = e; //ֻ���� Ȩ�޿�����С
//
//	int ii = 1;
//	double dd = ii;//�ᷢ����ʽ����ת��
//	//double& rdd = ii;//err
//	const double& rdd = ii;
//
//	const int& x = 10; //����Ҳ�������ڳ���
//	//�������õĽ��նȺܴ����������Ժ󣬾�����const
//	return 0;
//}


//void func1(int n)
//{}
//
////void func2(int& n)
//// ���ʹ�����ô��Σ�������������ı�n����ô���龡����const���ô��Ρ�
//void func2(const int& n)
//{}
//int main()
//{
//	int a = 10;
//	const int b = 20;
//	func1(a);
//	func1(b); //��Ϊ�����е������ǿ�����ȥ�ģ����Բ�Ӱ��b
//	func1(30); //ͬ��
//
//	func2(a);
//	func2(b);          //������������const�Ļ���Ȩ�޷Ŵ�,�ͻ�err
//	func2(30);           //ͬ��
//	func2(1.11);
//	double d = 2.22;
//	func2(d);
//
//	return 0;
//}



int main()
{
	//�﷨�ĽǶȣ�raû�п��ռ�
	int a = 10;
	int& ra = a;
	ra = 20;

	//�﷨�ĽǶȣ�pa���� 4 �� 8 byte�ռ�
	int* pa = &a;
	*pa = 20;

	return 0;
}