#define _CRT_SECURE_NO_WARNINGS

/*#include <iostream>

using namespace std;

// ����ָ�룺
// 1������RAII˼�����delete��Դ����
// 2����ָ��һ������Ϊ
// 3�����Ǵ��ڿ�������
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		cout << "delete:" << _ptr << endl;
		delete _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

private:
	T* _ptr;
};


//int div()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("��0����");
//
//	return a / b;
//}
//
////void Func()
////{
////	// 1�����p1����new ���쳣����Σ� 
////	// 2�����p2����new ���쳣����Σ�
////	// 3�����div���������ֻ����쳣����Σ�    �����ڴ�й¶
////	int* p1 = new int;
////	int* p2 = new int;
////
////	cout << div() << endl;
////
////	delete p1;
////	delete p2;
////	cout << "�ͷ���Դ" << endl;
////}
//
//void Func()
//{
//	// 1�����p1����new ���쳣����Σ� 
//	// 2�����p2����new ���쳣����Σ�
//	// 3�����div���������ֻ����쳣����Σ�   ���������򣬻������쳣�������������
//	SmartPtr<int> sp1(new int);
//	SmartPtr<int> sp2(new int);
//
//	*sp1 = 0;
//	*sp2 = 2;
//
//	cout << div() << endl;
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}





class A
{
public:
	~A()
	{
		cout << "~A()" << endl;
	}
	//private:
	int _a1 = 0;
	int _a2 = 0;
};

// C++98
// auto_ptr  ��Դ����Ȩת�ƣ��������εĿ������ᵼ�±�������������
// auto_ptr  �������������ڳ������ϣ��ܶ๫˾��ȷҪ����ʹ����

// boost     // boost����C++��׼ίԱ���Ա������
// scoped_ptr
// shared_ptr
// weak_ptr

// C++11    // ��boost��ҵ
// unique_ptr 
// shared_ptr
// weak_ptr

int main()
{
	auto_ptr<A> ap1(new A);   // ���е�auto_ptr��������
	ap1->_a1++;
	ap1->_a2++;
	// �������⣺
	auto_ptr<A> ap2(ap1);   // �൱����Դת�ƣ�ap1���ɿ�ָ�룬�ǲ������εĿ���
	ap1->_a1++;
	ap1->_a2++;


	SmartPtr<A> sp1(new A); // �Լ�ʵ�ֵ�Ҳ��������
	sp1->_a1++;
	sp1->_a2++;
	// �������⣺
	//SmartPtr<A> sp2(sp1);  // err ǳ������ָ��ָ��ͬһ��ռ�

	return 0;
}

*/



//// ����ָ��
#include <iostream>
#include <string>
#include <memory>


using namespace std;

#include "SmartPtr.h"

//int main()
//{
//	// test_auto_ptr();
//	
//	// test_unique_ptr();
//	
//	// test_shared_ptr1();
//
//	// test_shared_ptr2();
//	
//	// test_shared_ptr3();
//	
//	test_shared_ptr4();
//
//	
//	return 0;
//}


//////////////////////////////////////////////////////////
// ���һ���ֻ࣬���ڶ��ϴ�������
class HeapOnly
{
public:
	//static void Delete(HeapOnly* ptr)
	//{
	//	delete ptr;
	//}

	void Delete()
	{
		delete this;
	}

	// �ṩһ�����еģ���ȡ����ķ�ʽ�����������new������
	static HeapOnly* CreateObj()
	{
		return new HeapOnly;
	}

	// �����������ÿ�������͸�ֵ����ΪĬ�ϵĿ�������͸�ֵ����ջ�ϵ�
	HeapOnly(const HeapOnly& hp) = delete;
	HeapOnly& operator=(const HeapOnly& hp) = delete;
private:
	// ���캯��˽�л�
	HeapOnly()
		:_a(0)
	{}

	// ��������˽�л�
	//~HeapOnly()
	//{
	//	std::cout << "~HeapOnly" << std::endl;
	//}
private:
	int _a;
};

//int main()
//{
//	//HeapOnly hp1;
//	//static HeapOnly hp2;
//	//
//	//HeapOnly* ptr = new HeapOnly;
//	//// HeapOnly::Delete(ptr);
//	//ptr->Delete();
//
//	HeapOnly* hp3 = HeapOnly::CreateObj();
//	hp3->Delete();
//
//	return 0;
//}

/////////////////////////////////////////////////////////
// ֻ����ջ�ϴ�������
class StackOnly
{
public:
	static StackOnly CreateObj()
	{
		StackOnly st;
		return st;
	}

	// ���ܷ�����
	//StackOnly(const StackOnly& st) = delete;
	//StackOnly& operator=(const StackOnly& st) = delete;
	
	// ������ʱ��new
	void* operator new(size_t n) = delete;
private:
	// ���캯��˽�л�
	StackOnly()
		:_a(0)
	{}

private:
	int _a;
};

int main()
{
	StackOnly st1 = StackOnly::CreateObj();

	// ��������
	static StackOnly copy2(st1);  // ���ô�������һ��Сȱ��
	// StackOnly* copy3 = new StackOnly(st1);

	return 0;
}





///////////////////////////////////////////////////////////////////
// ����ģʽ -- һ��ʼ(main����֮ǰ)�ʹ���������
// �ŵ㣺�򵥡�û���̰߳�ȫ���� 
// ȱ�㣺
// 1��һ�������У�����������������Ⱥ󴴽���ʼ��˳��Ҫ��ʱ�������޷����ơ�
// �����������������A �� B������Ҫ��A�ȴ�����ʼ����B�ٴ�����ʼ����
// 2�����������࣬��ʼ��ʱ����࣬��Ӱ����������ٶȡ�

class MemoryPool
{
public:

private:
	// ���캯��˽�л�
	MemoryPool()
	{}

	char* _ptr = nullptr;
	// ...

	static MemoryPool _inst; // ����
};

// ����
MemoryPool MemoryPool::_inst;

class MemoryPool
{
public:
	static MemoryPool* GetInstance()
	{
		return _pinst;
	}

	void* Alloc(size_t n)
	{
		void* ptr = nullptr;
		// ....
		return ptr;
	}

	void Dealloc(void* ptr)
	{
		// ...
	}

private:
	// ���캯��˽�л�
	MemoryPool()
	{}

	char* _ptr = nullptr;
	// ...

	static MemoryPool* _pinst; // ����
};

// ����
MemoryPool* MemoryPool::_pinst = new MemoryPool;

/////////////////////////////////////////////////////////////////////////////////////
// ����ģʽ����һ��ʹ�ö����ٴ���ʵ������
// �ŵ㣺
// 1������˳��
// 2����Ӱ�������ٶȡ�

// ȱ�㣺
// 1����Ը��ӡ����̰߳�ȫ����û����
// 2���̰߳�ȫ����Ҫ�����
class MemoryPool
{
public:
	static MemoryPool* GetInstance()
	{
		if (_pinst == nullptr)
		{
			_pinst = new MemoryPool;
		}

		return _pinst;
	}

	void* Alloc(size_t n)
	{
		void* ptr = nullptr;
		// ....
		return ptr;
	}

	void Dealloc(void* ptr)
	{
		// ...
	}

	// ʵ��һ����Ƕ����������    
	class CGarbo {
	public:
		~CGarbo()
		{
			if (_pinst)
				delete _pinst;
		}
	};

private:
	// ���캯��˽�л�
	MemoryPool()
	{
		// ....
	}

	char* _ptr = nullptr;
	// ...

	static MemoryPool* _pinst; // ����
};

// ����
MemoryPool* MemoryPool::_pinst = nullptr;

// ���ն���main����������������������������ͻ��ͷŵ�������
static MemoryPool::CGarbo gc;


// ���������ͷ����⣺
// 1��һ������£�����������Ҫ�ͷŵġ���Ϊһ���������������ڼ䶼���ܻ�������
// ���������ڽ�������������Ҳ����Դ�ͷš�
// 2����Щ���ⳡ����Ҫ�ͷţ����絥����������ʱ��Ҫ����һЩ�־û�(���ļ������ݿ�д)������
// 

int main()
{
	//MemoryPool pool1;
	//MemoryPool pool2;

	void* ptr1 = MemoryPool::GetInstance()->Alloc(10);
	MemoryPool::GetInstance()->Dealloc(ptr1);
}