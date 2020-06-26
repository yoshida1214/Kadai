void CountingSort(int* in, int* out, const int cnt, const int max) {

    int* counter = new int[max + 1];
    for (int i = 0;i <= max;i++) {
        counter[i] = 0;
    }
    for (int i = 0;i < cnt;i++) {
        counter[in[i]]++;
    }
    for (int i = 1;i <= max;i++) {
        counter[i] += counter[i - 1];
    }
    for (int i = cnt - 1;i >= 0;i--) {
        out[counter[in[i]] - 1] = in[i];
        counter[in[i]]--;
    }
    delete[] counter;
}