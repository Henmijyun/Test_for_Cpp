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


	// ��ģ��shared_ptr :�������ü���
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			: _ptr(ptr)
		{}

		shared_ptr(shared_ptr<T>& sp)
			:_ptr(sp._ptr)
		{
			++_count;   // ÿ�μ���++
		}

		// ap1 = ap2
		shared_ptr<T>& operator=(shared_ptr<T>& ap)
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

		~shared_ptr()
		{
			if (--_count == 0 && _ptr)
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

		static int _count;  // ���ü���
	};
	// ��̬����
	template<class T>
	int shared_ptr<T>::_count = 0;

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
void test_shared_ptr()
{
	skk::shared_ptr<A> sp1(new A);
	skk::shared_ptr<A> sp2(sp1);
	skk::shared_ptr<A> sp3(sp2);

	sp1->_a1++;
	sp1->_a2++;  // 1 1
	cout << sp1->_a1 << ":" << sp1->_a2 << endl;

	sp2->_a1++;
	sp2->_a2++;   // 2 2
	cout << sp2->_a1 << ":" << sp2->_a2 << endl;
}