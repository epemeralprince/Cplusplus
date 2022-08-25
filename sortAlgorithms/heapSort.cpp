#include <iostream>
#include "sorts.h"

using std::cout;
using std::endl;


void swap(vector<int>& vi, int i, int j) {
    if (i!=j) {
        vi[i] ^= vi[j];
        vi[j] ^= vi[i];
        vi[i] ^= vi[j];
    }
}

void heapify(vector<int>& vi, int start, int end) {
    int f = start, s = start*2+1;
    while (s < end) {
        if (s+1<end && vi[s] < vi[s+1])
            s++;
        if (vi[s] <= vi[f])
            return;
        else {
            swap(vi, s, f);
            f = s;
            s = f*2+1;
        }
    }

}


void heapSort(vector<int>& vi) {
    for (int i = vi.size()/2-1; i>= 0; i--) {
        heapify(vi, i, vi.size());
    }
    for (int i = vi.size()-1; i > 0; i--) {
        swap(vi, 0, i);
        heapify(vi, 0, i);
    }
}

