
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



// 条件变量
int main()
{
	int i = 0;
	int n = 100;
	mutex mtx;
	condition_variable cv;
	bool ready = false;

	// 打印奇数
	thread t1([&]() ->void {
		while (i < n)
		{
			unique_lock<mutex> lock(mtx);
			cv.wait(lock, [&ready]() {return !ready; });  // 仿函数返回值为false，会阻塞等待，一直锁住

			std::cout << this_thread::get_id() << ":" << i << std::endl;
			i += 1;

			ready = true;

			cv.notify_one();  // 唤醒，因为ready变为true，所以唤醒的是t2
		}
		});

	// 打印偶数
	thread t2([&]() ->void {
		while (i < n)
		{
			unique_lock<mutex> lock(mtx);
			cv.wait(lock, [&ready]() {return ready; }); // 仿函数返回值为true，不会阻塞等待，则不会锁住

			std::cout << this_thread::get_id() << ":" << i << std::endl;
			i += 1;

			ready = false;

			cv.notify_one();  // 唤醒，因为ready变为false，所以唤醒的是t1

		}
		});

	std::cout << "t1:" << t1.get_id() << std::endl;
	std::cout << "t2:" << t2.get_id() << std::endl;

	t1.join();
	t2.join();




	return 0;
}






