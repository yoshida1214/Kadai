
int bubbleSort(int* a, const int cnt) {
    
    int changeCount = 0;    // �������J�E���g�p
    bool loopFlag = true;   // �t�̗אڗv�f�����݂���
    

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

