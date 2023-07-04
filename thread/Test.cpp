
#include <iostream>
#include <vector>
#include <thread>
#include <condition_variable>
#include <mutex>

using namespace std;

// mutex mtx; // ȫ��

//void Print(int n, mutex& mtx)  // ֻҪ���̵߳Ĵ��Σ���Զ�ǿ�������
//{
//	mtx.lock();  // ����
//
//	for (int i = 0; i < n; ++i)
//	{
//		cout << this_thread::get_id() << ":" << i << endl;
//		this_thread::sleep_for(std::chrono::milliseconds(1));
//	}
//
//	mtx.unlock();  // ����
//}

//void Print(int n, int& x, mutex& mtx)
//{
//	mtx.lock();  // ����
//
//	for (int i = 0; i < n; ++i)
//	{
//		cout << this_thread::get_id() << ":" << i << endl;
//		this_thread::sleep_for(std::chrono::milliseconds(1));
//		++x;
//	}
//
//	mtx.unlock();  // ����
//}
//
//int main()
//{
//	mutex m; // �ֲ�
//	int count = 0;
//
//	// thread t1(Print, 100, m);   // �����ǿ�����ֻҪ�Ǵ��εĶ��ǡ�
//	
//	thread t1(Print, 10, ref(count), ref(m));
//	thread t2(Print, 10, ref(count), ref(m));
//
//	t1.join();
//	t2.join();
//
//	cout << count << endl;
//
//	return 0;
//}



//int main()
//{
//	mutex mtx; // �ֲ�
//	int x = 0;
//	int n = 10;
//
//	// �����÷º�������lambda���ʽ�����д���
//	thread t1([&]()->void {
//		mtx.lock();  // ����
//		for (int i = 0; i < n; ++i)
//		{
//			std::cout << this_thread::get_id() << ":" << i << std::endl;
//			this_thread::sleep_for(std::chrono::milliseconds(1));
//			++x;
//		}
//		mtx.unlock();  // ����
//	});
//
//
//	t1.join();
//
//
//	std::cout << x << std::endl;
//
//	return 0;
//}


//int main()
//{
//	mutex mtx; // �ֲ�
//	int x = 0;
//	int n = 10;
//	int m;
//	cin >> m;
//	//vector<thread> v;
//	//v.resize(m);   // ����m���ռ�
//
//	vector<thread> v(m);
//	for (int i = 0; i < m; ++i)
//	{
//		// �������������ƶ���ֵ��vector�е��̶߳���
//		v[i] = thread ([&]()->void {
//			mtx.lock();  // ����
//			for (int i = 0; i < n; ++i)
//			{
//				std::cout << this_thread::get_id() << ":" << i << std::endl;
//				this_thread::sleep_for(std::chrono::milliseconds(1));
//				++x;
//			}
//			mtx.unlock();  // ����
//		});
//	}
//
//	for (int i = 0; i < m; ++i)
//	{
//		v[i].join();
//	}
//
//
//	std::cout << x << std::endl;
//
//	return 0;
//}



//int main()
//{
//	mutex mtx; 
//	atomic<int> x = 0;
//	//int x = 0;
//	int n = 1000000;
//	int m;
//	cin >> m;
//
//	vector<thread> v(m);
//	for (int i = 0; i < m; ++i)
//	{
//		v[i] = thread ([&]()->void {
//			for (int i = 0; i < n; ++i)
//			{
//				// û�м���������CAS����++
//				++x;
//			}
//		});
//
//		//v[i] = thread([&]()->void {
//		//	
//		//	for (int i = 0; i < n; ++i)
//		//	{
//		//		mtx.lock();  // ����  ��������m*n��
//		//		++x;
//		//		mtx.unlock();
//		//	}
//		//});
//	}
//
//	for (int i = 0; i < m; ++i)
//	{
//		v[i].join();
//	}
//
//
//	std::cout << x << std::endl;
//
//	return 0;
//}




//int main()
//{
//	mutex mtx; 
//	atomic<int> x = 0;
//	//int x = 0;
//	int n = 1000000;
//	int m;
//	cin >> m;
//
//	vector<thread> v(m);
//	for (int i = 0; i < m; ++i)
//	{
//		v[i] = thread([&]()->void {
//			
//			for (int i = 0; i < n; ++i)
//			{
//				mtx.lock();  
//				
//				// ��������������쳣��������
//				try {
//					std::cout << this_thread::get_id() << ":" << i << std::endl;
//					this_thread::sleep_for(std::chrono::milliseconds(1));
//					++x;
//				}
//				catch (...)
//				{
//					// �����쳣������ʲô��ʲô
//					mtx.unlock();   // �׵�ʱ�����
//					throw;
//				}
//
//				
//
//			}
//		});
//	}
//
//	for (int i = 0; i < m; ++i)
//	{
//		v[i].join();
//	}
//
//
//	std::cout << x << std::endl;
//
//	return 0;
//}


//// RAII
//template<class Lock>
//class LockGuard
//{
//public:
//	// ����ʱ����
//	LockGuard(Lock& lk)
//		:_lock(lk)
//	{
//		cout << "thread: " << this_thread::get_id() << "����" << endl;
//		_lock.lock();
//	}
//
//	// ����ʱ����
//	~LockGuard()
//	{
//		cout << "thread: " << this_thread::get_id() << "����" << endl << endl;
//		_lock.unlock();
//	}
//private:
//	Lock& _lock;   // ���洫�������� ������
//};
//
//int main()
//{
//	mutex mtx; 
//	//atomic<int> x = 0;
//	int x = 0;
//	int n = 100;
//	int m;
//	cin >> m;
//
//	vector<thread> v(m);
//	for (int i = 0; i < m; ++i)
//	{
//		v[i] = thread([&]()->void {
//			for (int i = 0; i < n; ++i)
//			{
//				// LockGuard<mutex> lk(mtx);  // �Լ�ʵ�ֵ�
//				lock_guard<mutex> lk(mtx);   // �������
//				std::cout << this_thread::get_id() << ":" << i << std::endl;
//				this_thread::sleep_for(std::chrono::milliseconds(1));
//				++x;
//			}
//		});
//	}
//
//	for (int i = 0; i < m; ++i)
//	{
//		v[i].join();
//	}
//
//
//	std::cout << x << std::endl;
//
//	return 0;
//}



// �����߳̽����ӡ1~100��һ����ӡ������һ����ӡż��
//int main()
//{
//	int i = 0;
//	int n = 100;
//
//	thread t1([&]() ->void {
//		while (i < n)
//		{
//			while (i % 2 != 0)
//			{
//				this_thread::yield(); // �ó�ʱ��Ƭ
//			}
//			cout << this_thread::get_id() << ":" << i << endl;
//			i += 1;
//		}
//	});
//
//	thread t2([&]() ->void {
//		while (i < n)
//		{
//			while (i % 2 == 0)
//			{
//				this_thread::yield(); // �ó�ʱ��Ƭ
//			}
//			cout << this_thread::get_id() << ":" << i << endl;
//			i += 1;
//		}
//	});
//
//	t1.join();
//	t2.join();
//	
//	return 0;
//}



//// ��������
//int main()
//{
//	int i = 0;
//	int n = 100;
//	mutex mtx;
//	condition_variable cv;
//	bool ready = false;
//
//	// ��ӡ����
//	thread t1([&]() ->void {
//		while (i < n)
//		{
//			unique_lock<mutex> lock(mtx);
//			cv.wait(lock, [&ready]() {return !ready; });  // �º�������ֵΪfalse���������ȴ���һֱ��ס
//
//			std::cout << "t1--" << this_thread::get_id() << ":" << i << std::endl;
//			i += 1;
//
//			ready = true;
//
//			cv.notify_one();  // ���ѣ���Ϊready��Ϊtrue�����Ի��ѵ���t2
//		}
//		});
//
//	// ��ӡż��
//	thread t2([&]() ->void {
//		while (i < n)
//		{
//			unique_lock<mutex> lock(mtx);
//			cv.wait(lock, [&ready]() {return ready; }); // �º�������ֵΪtrue�����������ȴ����򲻻���ס
//
//			std::cout << "t2--" << this_thread::get_id() << ":" << i << std::endl;
//			i += 1;
//
//			ready = false;
//
//			cv.notify_one();  // ���ѣ���Ϊready��Ϊfalse�����Ի��ѵ���t1
//
//		}
//		});
//
//	std::cout << "t1:" << t1.get_id() << std::endl;
//	std::cout << "t2:" << t2.get_id() << std::endl;
//
//	t1.join();
//	t2.join();
//
//
//
//
//	return 0;
//}



//#include<memory>
//
//namespace skk
//{
//	template<class T>
//	class shared_ptr
//	{
//	public:
//		shared_ptr(T* ptr = nullptr)
//			:_ptr(ptr)
//			, _pRefCount(new int(1))
//			, _pMutex(new mutex)
//		{}
//
//		shared_ptr(const shared_ptr<T>& sp)
//			:_ptr(sp._ptr)
//			, _pRefCount(sp._pRefCount)
//			, _pMutex(sp._pMutex)
//		{
//			AddRef();
//		}
//
//		void Release()
//		{
//			bool flag = false;
//
//			_pMutex->lock();
//			if (--(*_pRefCount) == 0 && _ptr)
//			{
//				cout << "delete:" << _ptr << endl;
//				delete _ptr;
//				delete _pRefCount;
//
//				flag = true;
//			}
//			_pMutex->unlock();
//
//			if (flag)
//				delete _pMutex;
//		}
//
//		void AddRef()
//		{
//			_pMutex->lock();
//
//			++(*_pRefCount);
//
//			_pMutex->unlock();
//		}
//
//		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
//		{
//			if (_ptr != sp._ptr)
//			{
//				Release();
//
//				_ptr = sp._ptr;
//				_pRefCount = sp._pRefCount;
//				_pmtx = sp._pmtx;
//				AddRef();
//			}
//
//			return *this;
//		}
//
//		int use_count()
//		{
//			return *_pRefCount;
//		}
//
//		~shared_ptr()
//		{
//			Release();
//		}
//
//		// ��ָ��һ��ʹ��
//		T& operator*()
//		{
//			return *_ptr;
//		}
//
//		T* operator->()
//		{
//			return _ptr;
//		}
//
//		T* get() const
//		{
//			return _ptr;
//		}
//	private:
//		T* _ptr;
//		int* _pRefCount;
//		mutex* _pMutex;
//	};
//}
//
//int main()
//{
//	// shared_ptr���̰߳�ȫ����
//	std::shared_ptr<double> sp1(new double(1.11));
//	std::shared_ptr<double> sp2(sp1);
//
//	mutex mtx;
//
//	vector<thread> v(2);
//	int n = 100000;
//	for (auto& t : v)
//	{
//		t = thread([&](){
//			for (size_t i = 0; i < n; ++i)
//			{
//				// �������̰߳�ȫ��
//				// skk::shared_ptr<double> sp(sp1);
//				std::shared_ptr<double> sp(sp1);
//
//				// ������Դ����
//				mtx.lock();
//				(*sp)++;
//				mtx.unlock();
//			}
//		});
//	}
//
//	for (auto& t : v)
//	{
//		t.join();
//	}
//
//	cout << sp1.use_count() << endl;
//	cout << *sp1 << endl;
//
//	return 0;
//}



//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		// ������һ�Σ���������Ҫ����
//		// ˫������
//		if (_pInstance == nullptr)
//		{
//			unique_lock<mutex> lock(_mtx);
//			if (_pInstance == nullptr)
//			{
//				_pInstance = new Singleton;
//			}
//		}
//
//		return _pInstance;
//	}
//
//private:
//	// ���캯��˽��
//	Singleton(){};
//
//	// C++11
//	Singleton(Singleton const&) = delete;
//	Singleton& operator=(Singleton const&) = delete;
//
//	static Singleton* _pInstance;
//	static mutex _mtx;
//};
//
//Singleton* Singleton::_pInstance = nullptr;
//mutex Singleton::_mtx; 
//
//int main()
//{
//	Singleton::GetInstance();
//	Singleton::GetInstance();
//
//	return 0;
//}

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		// �ֲ��ľ�̬���󣬵�һ�ε���ʱ��ʼ��

		// ��C++11֮ǰ�ǲ��ܱ�֤�̰߳�ȫ��
		// C++11֮ǰ�ֲ���̬����Ĺ��캯�����ó�ʼ�������ܱ�֤�̰߳�ȫ��ԭ���ԡ�
		// C++11��ʱ���޸���������⣬��������д����ֻ����֧��C++11�Ժ�ı���������
		static Singleton _s;

		return &_s;
	}

private:
	// ���캯��˽��
	Singleton() {};

	// C++11
	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;
};

int main()
{
	Singleton::GetInstance();
	Singleton::GetInstance();

	return 0;
}

