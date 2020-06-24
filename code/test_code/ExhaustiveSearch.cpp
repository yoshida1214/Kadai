
#include <iostream>
#include <math.h>
using namespace std;

bool _ExhaustiveSearch(const int* arrayValue, bool* checkFlag, const int arrayCnt, const int key, const int checkValue) {

    // �����ȊO�̍��v�l���v�Z
    int v = 0;
    for (int i = 0;i < key;i++) {
        v += arrayValue[i] * ((checkFlag[i]) ? 1 : 0);
        //if(checkFlag[i])
            //cout << arrayValue[i] << " ";
    }
    //cout << arrayValue[key] << endl;

    // �����𑫂��Ĉ�v�����ꍇ��true
    if ((v + arrayValue[key]) == checkValue) {
        checkFlag[key] = true;
        return true;
    }
    // key���Ō�ł����false��Ԃ�
    else if (key + 1 >= arrayCnt) {
        return false;
    }

    // ������true�̏ꍇ���`�F�b�N
    checkFlag[key] = true;
    if (_ExhaustiveSearch(arrayValue, checkFlag, arrayCnt, key + 1, checkValue))
        return true;
    else {
        // ������false�̏ꍇ���`�F�b�N
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