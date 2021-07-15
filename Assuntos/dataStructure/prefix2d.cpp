struct pf2d {
    int n, m;
    vector<vector<int> > pre;

    pf2d(){};
    pf2d(vector<vector<int> > mat, int n, int m) {
        this->n = n;
        this->m = m;
        precalc(mat);
    };
    void precalc(vector<vector<int> > mat) {
        this->pre.resize(n + 2, vector<int>(m + 2, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pre[i][j] += mat[i - 1][j - 1];
                pre[i][j] += pre[i - 1][j];
                pre[i][j] += pre[i][j - 1];
                pre[i][j] -= pre[i - 1][j - 1];
            }
        }
    }
    void cornerSwap(int &x1, int &y1, int &x2, int &y2) {
        if (x2 < x1) {
            swap(x2, x1);
        }
        if (y2 < y1) {
            swap(y2, y1);
        }
    }
    int size(int x1, int y1, int x2, int y2) {
        cornerSwap(x1, y1, x2, y2);
        return pre[x2][y2] + pre[x1 - 1][y1 - 1] - pre[x1 - 1][y2] -
               pre[x2][y1 - 1];
    }
};