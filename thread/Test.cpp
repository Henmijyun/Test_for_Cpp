
#include <iostream>
#include <vector>
#include <thread>
#include <condition_variable>
#include <mutex>

using namespace std;

// mutex mtx; // 全局

//void Print(int n, mutex& mtx)  // 只要是线程的传参，永远是拷贝！！
//{
//	mtx.lock();  // 加锁
//
//	for (int i = 0; i < n; ++i)
//	{
//		cout << this_thread::get_id() << ":" << i << endl;
//		this_thread::sleep_for(std::chrono::milliseconds(1));
//	}
//
//	mtx.unlock();  // 解锁
//}

//void Print(int n, int& x, mutex& mtx)
//{
//	mtx.lock();  // 加锁
//
//	for (int i = 0; i < n; ++i)
//	{
//		cout << this_thread::get_id() << ":" << i << endl;
//		this_thread::sleep_for(std::chrono::milliseconds(1));
//		++x;
//	}
//
//	mtx.unlock();  // 解锁
//}
//
//int main()
//{
//	mutex m; // 局部
//	int count = 0;
//
//	// thread t1(Print, 100, m);   // 这里是拷贝，只要是传参的都是。
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
//	mutex mtx; // 局部
//	int x = 0;
//	int n = 10;
//
//	// 可以用仿函数或者lambda表达式，进行传参
//	thread t1([&]()->void {
//		mtx.lock();  // 加锁
//		for (int i = 0; i < n; ++i)
//		{
//			std::cout << this_thread::get_id() << ":" << i << std::endl;
//			this_thread::sleep_for(std::chrono::milliseconds(1));
//			++x;
//		}
//		mtx.unlock();  // 解锁
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
//	mutex mtx; // 局部
//	int x = 0;
//	int n = 10;
//	int m;
//	cin >> m;
//	//vector<thread> v;
//	//v.resize(m);   // 开辟m个空间
//
//	vector<thread> v(m);
//	for (int i = 0; i < m; ++i)
//	{
//		// 从匿名对象中移动赋值给vector中的线程对象
//		v[i] = thread ([&]()->void {
//			mtx.lock();  // 加锁
//			for (int i = 0; i < n; ++i)
//			{
//				std::cout << this_thread::get_id() << ":" << i << std::endl;
//				this_thread::sleep_for(std::chrono::milliseconds(1));
//				++x;
//			}
//			mtx.unlock();  // 解锁
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
//				// 没有加锁，利用CAS进行++
//				++x;
//			}
//		});
//
//		//v[i] = thread([&]()->void {
//		//	
//		//	for (int i = 0; i < n; ++i)
//		//	{
//		//		mtx.lock();  // 并行  加锁解锁m*n次
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
//				// 这里如果存在抛异常就死锁了
//				try {
//					std::cout << this_thread::get_id() << ":" << i << std::endl;
//					this_thread::sleep_for(std::chrono::milliseconds(1));
//					++x;
//				}
//				catch (...)
//				{
//					// 任意异常，捕到什么抛什么
//					mtx.unlock();   // 抛的时候解锁
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
//	// 构造时上锁
//	LockGuard(Lock& lk)
//		:_lock(lk)
//	{
//		cout << "thread: " << this_thread::get_id() << "加锁" << endl;
//		_lock.lock();
//	}
//
//	// 析构时解锁
//	~LockGuard()
//	{
//		cout << "thread: " << this_thread::get_id() << "解锁" << endl << endl;
//		_lock.unlock();
//	}
//private:
//	Lock& _lock;   // 外面传进来的锁 的引用
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
//				// LockGuard<mutex> lk(mtx);  // 自己实现的
//				lock_guard<mutex> lk(mtx);   // 库里面的
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



// 两个线程交错打印1~100，一个打印奇数，一个打印偶数
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
//				this_thread::yield(); // 让出时间片
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
//				this_thread::yield(); // 让出时间片
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



//// 条件变量
//int main()
//{
//	int i = 0;
//	int n = 100;
//	mutex mtx;
//	condition_variable cv;
//	bool ready = false;
//
//	// 打印奇数
//	thread t1([&]() ->void {
//		while (i < n)
//		{
//			unique_lock<mutex> lock(mtx);
//			cv.wait(lock, [&ready]() {return !ready; });  // 仿函数返回值为false，会阻塞等待，一直锁住
//
//			std::cout << "t1--" << this_thread::get_id() << ":" << i << std::endl;
//			i += 1;
//
//			ready = true;
//
//			cv.notify_one();  // 唤醒，因为ready变为true，所以唤醒的是t2
//		}
//		});
//
//	// 打印偶数
//	thread t2([&]() ->void {
//		while (i < n)
//		{
//			unique_lock<mutex> lock(mtx);
//			cv.wait(lock, [&ready]() {return ready; }); // 仿函数返回值为true，不会阻塞等待，则不会锁住
//
//			std::cout << "t2--" << this_thread::get_id() << ":" << i << std::endl;
//			i += 1;
//
//			ready = false;
//
//			cv.notify_one();  // 唤醒，因为ready变为false，所以唤醒的是t1
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
//		// 像指针一样使用
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
//	// shared_ptr是线程安全的吗？
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
//				// 拷贝是线程安全的
//				// skk::shared_ptr<double> sp(sp1);
//				std::shared_ptr<double> sp(sp1);
//
//				// 访问资源不是
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
//		// 保护第一次，后续不需要加锁
//		// 双检查加锁
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
//	// 构造函数私有
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
		// 局部的静态对象，第一次调用时初始化

		// 在C++11之前是不能保证线程安全的
		// C++11之前局部静态对象的构造函数调用初始化并不能保证线程安全的原子性。
		// C++11的时候修复了这个问题，所以这种写法，只能在支持C++11以后的编译器上玩
		static Singleton _s;

		return &_s;
	}

private:
	// 构造函数私有
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

