
#include <iostream>
#include <math.h>
using namespace std;

bool _ExhaustiveSearch(const int* arrayValue, bool* checkFlag, const int arrayCnt, const int key, const int checkValue) {

    // 自分以外の合計値を計算
    int v = 0;
    for (int i = 0;i < key;i++) {
        v += arrayValue[i] * ((checkFlag[i]) ? 1 : 0);
        //if(checkFlag[i])
            //cout << arrayValue[i] << " ";
    }
    //cout << arrayValue[key] << endl;

    // 自分を足して一致した場合はtrue
    if ((v + arrayValue[key]) == checkValue) {
        checkFlag[key] = true;
        return true;
    }
    // keyが最後であればfalseを返す
    else if (key + 1 >= arrayCnt) {
        return false;
    }

    // 自分がtrueの場合をチェック
    checkFlag[key] = true;
    if (_ExhaustiveSearch(arrayValue, checkFlag, arrayCnt, key + 1, checkValue))
        return true;
    else {
        // 自分がfalseの場合をチェック
        checkFlag[key] = false;
        if (_ExhaustiveSearch(arrayValue, checkFlag, arrayCnt, key + 1, checkValue))
            return true;
    }
    return false;
}

bool ExhaustiveSearch(const int* arrayValue, const int arrayCnt, const int checkValue) {
    bool* check;
    check = new bool[arrayCnt];
    return _ExhaustiveSearch(arrayValue, check, arrayCnt, 0, checkValue);
}