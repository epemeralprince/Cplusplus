// Compiler: MSVC 19.29.30038.1
// C++ Standard: C++17
#include <iostream>
#include <thread>
using namespace std;
int n = 0;
void count10000() {
	for (int i = 1; i <= 10000; i++)
		n++;
}
int main() {
	thread th[100];
	// 这里偷了一下懒，用了c++11的foreach结构
	for (thread &x : th)
		x = thread(count10000);
	for (thread &x : th)
		x.join();
	cout << n << endl;
	return 0;
}

// 为什么要有atomic和mutex