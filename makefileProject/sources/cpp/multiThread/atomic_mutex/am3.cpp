// Compiler: MSVC 19.29.30038.1
// C++ Standard: C++17
#include <iostream>
#include <thread>
// #include <mutex> //这个例子不需要mutex了
#include <atomic>
using namespace std;


// atomic_int n = 0;   //  复制构造函数已经删除，这行代码报错
atomic_int n(0);
// atomic<int> n(0);
void count10000() {
	for (int i = 1; i <= 10000; i++) {
		n++;
	}
}
int main() {
	thread th[100];
	for (thread &x : th)
		x = thread(count10000);
	for (thread &x : th)
		x.join();
	cout << n << endl;
	return 0;
}


// std::atomic的使用


/*
std::atomic_int只是std::atomic<int>的别名
atomic，本意为原子，官方 （我不确定是不是官方，反正继续解释就对了） 对其的解释是
	原子操作是最小的且不可并行化的操作。
这就意味着即使是多线程，也要像同步进行一样同步操作atomic对象，从而省去了mutex上锁、解锁的时间消耗。
*/

/*
std::atomic常用成员函数：              ---atomic没有显式定义析构函数---
	atomic() noexcept = default    默认构造函数	   构造一个atomic对象（未初始化，可通过atomic_init进行初始化）

	constexpr atomic(T val) noexcept    初始化构造函数    构造一个atomic对象，用val的值来初始化

	atomic(const atomic&) = delete   复制构造函数	 （已删除）

*/

// atomic能够直接当作普通变量使用，成员函数貌似没啥用，所以这里就不列举了