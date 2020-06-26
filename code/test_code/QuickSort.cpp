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