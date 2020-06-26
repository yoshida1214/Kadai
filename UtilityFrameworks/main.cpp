
#include <iostream>
#include <math.h>
using namespace std;

typedef struct _cost {
    int num;
    int index;
    bool operator > (_cost& c) { return num > c.num; }
    bool operator < (_cost& c) { return num < c.num; }
    bool operator >= (_cost& c) { return num >= c.num; }
    bool operator <= (_cost& c) { return num <= c.num; }
}cost;



template<typename T>
void Partition(T* in, int& index, const int cnt, const int startNum, const int endNum) {

    // 最後の要素をパーティションに設定
    T partition = in[endNum];
    int num = startNum - 1;

    for (int i = startNum; i < endNum;i++) {
        if (in[i] <= partition) {
            num++;
            T temp = in[num];
            in[num] = in[i];
            in[i] = temp;
        }
    }

    T temp = in[num + 1];
    in[num + 1] = in[endNum];
    in[endNum] = temp;
    index = num + 1;
}

template<typename T>
void _QuickSort(T* in, const int cnt, const int startNum, const int endNum) {
    if (startNum < endNum) {
        int index;
        Partition<T>(in, index, cnt, startNum, endNum);
        _QuickSort<T>(in, cnt, startNum, index - 1);
        _QuickSort<T>(in, cnt, index + 1, endNum);
    }
}

template<typename T>
void QuickSort(T* in, const int cnt) {
    _QuickSort<T>(in, cnt, 0, cnt - 1);
}

int MinimumCostSort(int *in,int cnt) {
    int cost = 0;
    int min,chngeCnt,start;
    min = -1;
    start = -1;
    bool loopFlag = true;
    _cost* result = new _cost[cnt];
    _cost* input = new _cost[cnt];
    for (int i = 0;i < cnt;i++) {
        result[i].num = in[i];
        result[i].index = i;
        input[i].num = in[i];
    }
    QuickSort(result, cnt);

    for (int i = 0;i < cnt;i++) {
        input[result[i].index].index = i;
    }


    while (loopFlag) {

        if (start < 0) {
            for (int i = 0;i < cnt;i++) {
                // スタートの位置を求める
                if (input[i].num != result[i].num) {
                    if (start < 0)
                        start = i;
                    else if (input[i].num < input[start].num)
                        start = i;
                }
                
                // 最小値を求める
                if (min < 0)
                    min = i;
                else if (input[i].num < input[min].num)
                    min = i;
            }
            if (start < 0) {
                break;
            }
        }

        // 交換回数を求める
        chngeCnt = 0;
        for (int check = start; input[start].num != result[check].num;check = result[check].index) {
            chngeCnt++;
        }


        // 最小値とスタートの値を交換したほうが効率がいい場合は交換を行う
        if ((input[start].num + input[min].num) * 2 < chngeCnt * (input[start].num - input[min].num)) {

            _cost temp = input[min];
            input[min] = input[start];
            input[start] = temp;
            cost += input[start].num + input[min].num;

            // result indexの交換
            result[input[start].index].index = start;
            result[input[min].index].index = min;
        }


        int index = result[start].index;
        _cost temp = input[index];
        input[index] = input[start];
        input[start] = temp;
        cost += input[start].num + input[index].num;

        // result indexの交換
        index = result[input[start].index].index;
        result[input[start].index].index = result[temp.index].index;
        result[temp.index].index = index;

        start = result[start].index;

        if (result[start].num == input[start].num) {
            start = -1;
        }
    }
    
    return cost;
}

int main() {
    int cnt,cost;
    int *n;
    // 入力
    cin >> cnt;
    n = new int[cnt];

    for (int i = 0;i < cnt;i++) {
        cin >> n[i];
    }
    
    cost = MinimumCostSort(n, cnt);
    cout << cost << endl;


    cin >> cnt;
    delete[] n;
    return 0;
}
