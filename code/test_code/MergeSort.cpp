
#include <iostream>
#include <math.h>
using namespace std;

void _merge(int* A, const int left, const int middle, const int right) {
    int all = 2147483647;
    int n1 = (middle - left) + 1;
    int n2 = (right - middle) + 1;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0;i < n1 - 1;i++) {
        L[i] = A[left + i];
        if (L[i] < 0)
            cout << "error" << endl;
    }
    for (int i = 0;i < n2 - 1;i++) {
        R[i] = A[middle + i];
        if (R[i] < 0)
            cout << "error" << endl;
    }
    L[n1 - 1] = (int)all;
    R[n2 - 1] = (int)all;
    int n1Cnt, n2Cnt;
    n1Cnt = n2Cnt = 0;

    for (int i = left;i < right;i++) {
        if ((int)L[n1Cnt] <= (int)R[n2Cnt]) {
            A[i] = L[n1Cnt];
            n1Cnt++;
        }
        else {
            A[i] = R[n2Cnt];
            n2Cnt++;
        }
        if (A[i] < 0)
            cout << "error" << endl;
    }
    delete[] L, R;
}
void _mergeSort(int* A, const int left, const int right) {
    int middle;
    if (left + 1 < right) {
        middle = (left + right) / 2;
        _mergeSort(A, left, middle);
        _mergeSort(A, middle, right);
        _merge(A, left, middle, right);
    }
}

void mergeSort(int* A, const int cnt) {
    _mergeSort(A, 0, cnt);
}