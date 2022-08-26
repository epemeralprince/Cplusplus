#include <iostream>
#include "sorts.h"

using std::cout;
using std::endl;


void subShellSort(vector<int>& vi, int start, int span) {
    for (int i = start+span; i < vi.size(); i+=span) {
        int j = i, cur = vi[i];
        for (; j >= span; j-=span) {
            if (cur >= vi[j-span])
                break;
            vi[j] = vi[j-span];
        }
        vi[j] = cur;
    }
}


void shellSort(vector<int>& vi) {
    int len = vi.size();
    int span = len>>1;
    while (span>0) {
        for (int i = 0; i < span; i++) {
            subShellSort(vi, i, span);
        }
        span >>= 1;
    }
}

