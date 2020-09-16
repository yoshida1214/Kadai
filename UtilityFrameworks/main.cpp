
/**/
#include <iostream>
#include <string.h>
#include <float.h>
using namespace std;    

int** graph(int** in, const int cnt) {

    int** out = new int* [cnt];
    for (int i = 0;i < cnt;i++) {
        out[i] = new int[cnt];
        for (int j = 0;j < cnt;j++)
            out[i][j] = 0;
    }

    for (int i = 0;i < cnt;i++) {
        int c = in[i][0]+1;
        for (int j = 1;j < c;j++) {
            out[i][in[i][j] - 1] = 1;
        }
    }

    return out;
}

int main() {
    int cnt,c;
    int** list,**ans;

    // “ü—Í
    cin >> cnt;
    list = new int*[cnt];
    for (int i = 0;i < cnt;i++) {
        cin >> c;
        cin >> c;
        list[i] = new int[c + 1];
        list[i][0] = c;
        for (int j = 1;j < c+1;j++)
            cin >> list[i][j];
    }

    ans = graph(list, cnt);

    for (int i = 0;i < cnt;i++) {
        for (int j = 0;j < cnt;j++) {
            cout << ans[i][j];
            if (j != cnt - 1)
                cout << " ";
            else
                cout << endl;
        }
    }
    

    for (int i = 0;i < cnt;i++) {
        delete[] list[i], ans[i];
    }
    delete list, ans;

    return 0;
}
/**/