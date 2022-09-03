// Compiler: MSVC 19.29.30038.1
// C++ Standard: C++17
#include <iostream>
#include <thread>
using namespace std;
void doit() { cout << "World!" << endl; }
int main() {
	// 这里的线程a使用了 C++11标准新增的lambda函数
	// 有关lambda的语法，请参考我之前的一篇博客
	// https://blog.csdn.net/sjc_0910/article/details/109230162
	thread a([]{
		cout << "Hello, " << flush;
	}), b(doit);
	// 一直显示 Hello, World!  这里的变量创建顺序是 a 再 b
	a.join();
	b.join();
	return 0;
}

// thread的基本使用

/*
std::thread常用成员函数
1、构造&析构函数
	thread() noexcept                          默认构造函数	     创建一个线程，什么也不做

	template <class Fn, class… Args>           初始化构造函数    创建一个线程，以args为参数执行fn函数
	explicit thread(Fn&& fn, Args&&… args)
	
	thread(const thread&) = delete             复制构造函数	     （已删除）
	thread(thread&& x) noexcept                移动构造函数	      构造一个与x相同的对象,会破坏x对象
	~thread()                                  析构函数           析构对象

2、常用成员函数
	void join()           等待线程结束并清理资源（会阻塞）
	bool joinable()	      返回线程是否可以执行join函数
	void detach()         将线程与调用其的线程分离，彼此独立执行（此函数必须在线程创建时立即调用，且调用此函数会使其不能被join）
				--------- detach调用之后，目标线程就成为了守护线程，驻留后台运行，与之关联的std::thread对象失去对目标线程的关联，
						  无法再通过std::thread对象取得该线程的控制权。当线程主函数执行完之后，线程就结束了，运行时库负责清理与该线程相关的资源。					
	std::thread::id get_id()	 获取线程id
	thread& operator=(thread &&rhs)   见移动构造函数（如果对象是joinable的，那么会调用std::terminate()结果程序）

*/



// CSDN c++多线程
// https://blog.csdn.net/sjc_0910/article/details/118861539?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522165935120416781685318694%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=165935120416781685318694&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-118861539-null-null.142^v37^new_blog_pos_by_title&utm_term=c%2B%2B%E5%A4%9A%E7%BA%BF%E7%A8%8B&spm=1018.2226.3001.4187