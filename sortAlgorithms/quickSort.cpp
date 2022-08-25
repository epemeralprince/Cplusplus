#include <iostream>
#include "sorts.h"

using std::cout;
using std::endl;


void subQuickSort(vector<int>& vi, int start, int end) {
    if (start >= end)
        return;
    int left = start, right = end, cur = vi[start];
    cout << "input: left = " << left << "  right = " << right << endl;
    for (auto i : vi) {
        cout << i << " ";
    }
    cout << endl;
    while (left < right) {
        while (right > left && vi[right] >= cur) {
            right--;
        }
        while (left < right && vi[left] <= cur) {
            left++;
        }
        if (left < right) {
            vi[left] ^= vi[right];
            vi[right] ^= vi[left];
            vi[left] ^= vi[right];
        }
        cout << "left = " << left << "  right = " << right << endl;
    }
    if (start != left) {
        vi[start] ^= vi[left];
        vi[left] ^= vi[start];
        vi[start] ^= vi[left];
    }
    for (auto i : vi) {
        cout << i << " ";
    }
    cout << endl;
    subQuickSort(vi, start, left-1);
    subQuickSort(vi, left+1, end);
}


void quickSort(vector<int>& vi) {
    subQuickSort(vi, 0, vi.size()-1);
}

