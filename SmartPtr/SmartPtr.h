#pragma once
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

// 1��RAII
// 2����ָ��һ��
// 3���������� -- > �ܶ�������
template<class T>
class SmartPtr {
public:
	SmartPtr(T* ptr = nullptr)
		: _ptr(ptr)
	{}

	~SmartPtr()
	{
		if (_ptr)
		{
			cout << "Delete:" << _ptr << endl;
			delete _ptr;
		}
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


namespace skk
{
	// ģ��ʵ��auto_ptr  ����Ȩת�ƣ�����̲�
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr = nullptr)
			: _ptr(ptr)
		{}

		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;  // ��ָ�����˹��������ÿգ��൱�ڽ���
		}

		// ap1 = ap2
		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr)
				{
					cout << "Delete:" << _ptr << endl;
					delete _ptr;
				}

				// ����Ȩת��
				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}
			return *this;
		}

		~auto_ptr()
		{
			if (_ptr)
			{
				cout << "Delete:" << _ptr << endl;
				delete _ptr;
			}
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


	// ģ��ʵ��unique_ptr :���ÿ���
	template<class T>
	class unique_ptr 
	{
	private:
		// ������C++98
		// ֻ������ʵ�֣�������Ϊ˽�У���ֹ�ⲿʵ��
		// unique_ptr(unique_ptr<T>& ap);
		// unique_ptr<T>& operator=(unique_ptr<T>& ap);
	public:
		unique_ptr(T* ptr = nullptr)
			: _ptr(ptr)
		{}

		// ��д���������������Զ�����
		// �����ñ���������Ĭ�Ͽ������� delete  ������
		unique_ptr(unique_ptr<T>& ap) = delete;

		// ������
		unique_ptr<T>& operator=(unique_ptr<T>& ap) = delete;


		// ������C++11
		/* unique_ptr(unique_ptr<T>& ap) = delete;
		   unique_ptr<T>& operator=(unique_ptr<T>& ap) = delete;
		 */


		~unique_ptr()
		{
			if (_ptr)
			{
				cout << "Delete:" << _ptr << endl;
				delete _ptr;
			}
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




	// ��ģ��shared_ptr :���þ�̬���������ü����������У� 
	//template<class T>
	//class shared_ptr
	//{
	//public:
	//	shared_ptr(T* ptr = nullptr)
	//		: _ptr(ptr)
	//	{
	//		++_count;
	//	}

	//	~shared_ptr()
	//	{
	//		if (--_count == 0 && _ptr)
	//		{
	//			cout << "Delete:" << _ptr << " count:" << &_count << endl;
	//			delete _ptr;
	//		}
	//	}

	//	shared_ptr(shared_ptr<T>& sp)
	//		: _ptr(sp._ptr)
	//	{
	//		++_count;
	//	}

	//	T& operator*()
	//	{
	//		return *_ptr;
	//	}

	//	T* operator->()
	//	{
	//		return _ptr;
	//	}

	//private:
	//	T* _ptr;
	//	static int _count;  // �þ�̬�����ķ�ʽ������
	//};
	// ��̬�����������У�
	//template<class T>
	//int shared_ptr<T>::_count = 0;





	// ��ģ��shared_ptr :����ָ�룬���ü��� 
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			: _ptr(ptr)
			, _pCount(new int(1))
		{}

		// sp1(sp2)
		shared_ptr(shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pCount(sp._pCount)
		{
			(*_pCount)++;
		}

		void Release()
		{
			if (--(*_pCount) == 0)
			{
				cout << "Delete:" << _ptr << " count:" << _pCount << endl;
				delete _ptr;
				delete _pCount;
			}
		}

		~shared_ptr()
		{
			Release();
		}

		// sp1 = sp5
		// sp1 = sp1 
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			//if (this == &sp)  // err �����е�ַ����ͬ������ָ��ͬһ��ռ�
			if (sp._ptr == _ptr)
			{
				return *this;
			}

			// ��������ֵ����ļ�������������һ������Ҫ�ͷ�
			/*if (--(*_pCount) == 0)
			{
				cout << "Delete:" << _ptr << " count:" << _pCount << endl;
				delete _ptr;
				delete _pCount;
			}*/
			Release();

			// ��������Դ��++����
			_ptr = sp._ptr;
			_pCount = sp._pCount;
			(*_pCount)++;

			return *this;
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
		int* _pCount;  // ÿ�ι���ʱ��newһ������
		// ���߳��У����ܴ�������
	};




}

// boost -- ̽·��
// scoped_ptr / shared_ptr / weak_ptr

// C++11 -- ��boost�����ҵ
// unique_ptr / shared_ptr / weak_ptr



// C++98 auto_ptr ����Ȩת�ƣ�����������������������
// �ܶ๫˾��ȷ��Ҫ����ʹ����
void test_auto_ptr()
{
	skk::auto_ptr<A> ap1(new A);
	ap1->_a1++;
	ap1->_a2++;

	skk::auto_ptr<A> ap2(ap1);
	ap2->_a1++;
	ap2->_a2++;

	// ap1->_a1++;  // err ap1����Դת�Ƶ���ap2
	// ap1->_a2++;  // err ap1����

	skk::auto_ptr<A> ap3(new A);
	ap2 = ap3;

	ap2->_a1++;  // 1 1
	ap2->_a2++;

	cout << ap2->_a1 << "  " << ap2->_a2 << endl;
}

// unique_ptr :�򵥴ֱ���ֱ�Ӳ��ÿ���
void test_unique_ptr()
{
	skk::unique_ptr<A> up1(new A);
	// skk::unique_ptr<A> up2(up1);    // err 
	up1->_a1++;
	up1->_a2++;
}

// shared_ptr :�������ü���
void test_shared_ptr1()
{
	skk::shared_ptr<A> sp1(new A);
	skk::shared_ptr<A> sp2(sp1);
	skk::shared_ptr<A> sp3(sp2);

	//skk::shared_ptr<int> sp4(new int);  // err ��̬�����ķ�ʽ
	//skk::shared_ptr<int> sp5(sp4);    // ���� A���͵Ķ��� �� int���͵Ķ��� ��ͬһ��count���м���

	skk::shared_ptr<int> sp4(new int);  // ok ָ�����
	skk::shared_ptr<A> sp5(new A);   
	skk::shared_ptr<A> sp6(sp5);

	sp1->_a1++;
	sp1->_a2++;  // 1 1
	cout << sp1->_a1 << ":" << sp1->_a2 << endl;

	sp2->_a1++;
	sp2->_a2++;   // 2 2
	cout << sp2->_a1 << ":" << sp2->_a2 << endl;

	sp1 = sp5;
	sp2 = sp5;
	sp3 = sp5;

	// �Լ����Լ���ֵ
	skk::shared_ptr<int> sp7(new int);
	sp7 = sp7;  // ����_pCount��0����ɱ��
	sp1 = sp5;  // ��ַ����ͬ������ָ��ͬһ��ռ�
}


struct Node
{
	int _val;
	/*std::shared_ptr<Node> _next;
	std::shared_ptr<Node> _prev;*/

	std::weak_ptr<Node> _next;
	std::weak_ptr<Node> _prev;

	~Node()
	{
		cout << "~Node" << endl;
	}
};

// ѭ������ -- weak_ptr���ǳ�������ָ�룬û��RAII����֧��ֱ�ӹ�����Դ
// weak_ptr��Ҫ��shared_ptr���죬�������shared_ptrѭ����������
void test_shared_ptr2()
{
	/*std::shared_ptr<Node> n1(new Node);
	std::shared_ptr<Node> n2(new Node);

	n1->_next = n2;
	n2->_prev = n1;*/

	std::shared_ptr<Node> n1(new Node);
	std::shared_ptr<Node> n2(new Node);

	cout << n1.use_count() << endl;
	cout << n2.use_count() << endl;

	n1->_next = n2;
	n2->_prev = n1;

	cout << n1.use_count() << endl;
	cout << n2.use_count() << endl;
}
