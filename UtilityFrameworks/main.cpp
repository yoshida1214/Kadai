#include <iostream>
using namespace std;

void insertionSort(int* A, int N) { // N個の要素を含む0-オリジンの配列A
    int v, j;
    for (int k = 0;k < N - 1;k++) {
        cout << A[k] << " ";
    }
    cout << A[N - 1] << endl;
    
    for (int i = 1;i < N;i++) { //i が 1 から N まで
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) { //j >= 0 かつ A[j] > v
            A[j + 1] = A[j];
            j--;
            A[j + 1] = v;
        }
        for (int k = 0;k < N - 1;k++) {
            cout << A[k] << " ";
        }
        cout << A[N - 1] << endl;
    }
}

int main() {
    int cnt;
    cin >> cnt;
    int* vec;
    vec = new int[cnt];

    for (int i = 0;i < cnt;i++)
        cin >> vec[i];
    insertionSort(vec, cnt);

    cin >> cnt;
    delete[] vec;
    return 0;
}