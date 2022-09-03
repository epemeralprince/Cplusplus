// Compiler: MSVC 19.29.30038.1
// C++ Standard: C++17
#include <iostream>
#include <thread>
using namespace std;
template<class T> void changevalue(T &x, T val) {
	x = val;
}
int main() {
	thread th[100];
	int nums[100];
	for (int i = 0; i < 100; i++)
		th[i] = thread(changevalue<int>, nums[i], i+1);
	for (int i = 0; i < 100; i++) {
		th[i].join();
		cout << nums[i] << endl;
	}
	return 0;
}
// 以右值传递，编译会报错
// thread执行带有引用参数的函数