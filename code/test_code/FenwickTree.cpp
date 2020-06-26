
typedef struct _fenwick_tree {
    int n;
    int* bit;
    // �e�v�f�̏����l�� 0
    _fenwick_tree(int num) :n(num) {
        bit = new int[n];
        for (int i = 0;i < n;i++)
            bit[i] = 0;
    }
    ~_fenwick_tree() {
        delete[] bit;
    }

    // a_i += w
    void add(int i, int w) {
        for (int x = i; x < n; x += x & -x) {
            bit[x] += w;
            if (x == 0)
                break;
        }
    }
    // [1, i] �̘a���v�Z.
    int sum(int i) {
        int ret = 0;
        for (int x = i; x > 0; x -= x & -x) {
            ret += bit[x];
        }
        return ret;
    }
    // [left+1, right] �̘a���v�Z.
    int sum(int left, int right) {
        return sum(right) - sum(left);
    }
}fenwick_tree;