
int bubbleSort(int* a, const int cnt) {
    
    int changeCount = 0;    // 交換数カウント用
    bool loopFlag = true;   // 逆の隣接要素が存在する
    

    while (loopFlag) {
        loopFlag = false;
        for (int i = cnt - 1;i >= 0;i--) {
            if (a[i] < a[i - 1]) {
                int temp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = temp;
                loopFlag = true;
                changeCount++;
            }
        }
    }
    return changeCount;
}

