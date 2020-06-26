void Partition(int* in, int& index, const int cnt, const int startNum, const int endNum) {

    // 最後の要素をパーティションに設定
    int partition = in[endNum];
    int num = startNum - 1;

    for (int i = startNum; i < endNum;i++) {
        if (in[i] <= partition) {
            num++;
            int temp = in[num];
            in[num] = in[i];
            in[i] = temp;
        }
    }

    int temp = in[num + 1];
    in[num + 1] = in[endNum];
    in[endNum] = temp;
    index = num + 1;
}