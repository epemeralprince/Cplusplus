#include "sorts.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>

using std::cout;
using std::endl;


int main(int argc, char* argv[]) {
    srand(time(0));
    cout << "in main function" << endl;
    vector<int> vi(30);
    for (int i = 0; i < vi.size(); i++) {
        vi[i] = rand()%101;
    }
    cout << "original vector:" << endl;
    for (auto i : vi) {
        cout << i << " ";
    }
    cout << endl;
    cout << "call quickSort function" << endl;
    subShellSort(vi, 0, 1);
    cout << "display sort result:" << endl;
    for (auto i : vi) {
        cout << i << " ";
    }
    cout << endl;
}