void Partition(int* in, int& index, const int cnt, const int startNum, const int endNum) {

    // �Ō�̗v�f���p�[�e�B�V�����ɐݒ�
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