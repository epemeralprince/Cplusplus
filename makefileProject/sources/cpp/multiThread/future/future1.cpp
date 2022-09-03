/*
C++11中的std::future
我们已经知道如何使用async来异步或同步执行任务，但如何获得函数的返回值呢？这时候，async的返回值std::future就派上用场了。

例七：使用std::future获取线程的返回值
*/

// Compiler: MSVC 19.29.30038.1
// C++ Standard: C++17
#include <iostream>
// #include <thread> // 这里我们用async创建线程
#include <future> // std::async std::future
using namespace std;

template<class ... Args> 
decltype(auto) sum(Args&&... args) {
	// C++17折叠表达式
	// "0 +"避免空参数包错误
	return (0 + ... + args);
}

int main() {
	// 注：这里不能只写函数名sum，必须带模板参数
	future<int> val = async(launch::async, sum<int, int, int>, 1, 10, 100);
	// future::get() 阻塞等待线程结束并获得返回值
	cout << val.get() << endl;
    //int value = sum<int, int, int>(1, 10, 100);
    //cout << value << endl;
	return 0;
}
