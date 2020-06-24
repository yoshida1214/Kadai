#include <iostream>
using namespace std;


int linearsearch() {


    // “ü—Í•”•ª
    int cntA, cntB, ans;
    int* a, * b;
    cin >> cntA;
    a = new int[cntA];
    for (int i = 0;i < cntA;i++) {
        cin >> a[i];
    }

    cin >> cntB;
    b = new int[cntB];
    for (int i = 0;i < cntB;i++) {
        cin >> b[i];
    }

    // ’Tõ•”•ª
    int buff = 0;
    ans = 0;
    for (int i = 0;i < cntB;i++) {
        int j = cntA / 2;
        int cnt = cntA;
        while (cnt) {
            cnt >>= 1;
            //cout << "b[" << i << "]=" << b[i] << "  a[" << j << "]=" << a[j] << "    buff = " << buff <<endl;
            if (b[i] == a[j]) {
                ans++;
                break;
            }
            else if (b[i] > a[j]) {
                buff = (cnt / 2) + (cnt % 2);
                j += buff;
            }
            else if (b[i] < a[j]) {
                buff = (cnt / 2) + (cnt % 2);
                j -= buff;
            }

        }
    }

    // o—Í•”•ª
    cout << ans << endl;
    delete[] a, b;
    return 0;
}