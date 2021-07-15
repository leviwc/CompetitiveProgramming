
struct sparSeg {
    sparSeg() {}
    struct node {
        node *l = nullptr, *r = nullptr;
        int value = 0;
    };
    node *raiz = new node();
    void update(int pos, int val) { update(pos, val, raiz, 0, 1e9 + 1); }
    void update(int pos, int val, node *v, int tl, int tr) {
        if (tl == tr) {
            v->value += val;
            return;
        }
        int med = (tl + tr) / 2;
        if (pos <= med) {
            if (v->l == nullptr) {
                v->l = new node();
            }
            update(pos, val, v->l, tl, med);
        } else {
            if (v->r == nullptr) {
                v->r = new node();
            }
            update(pos, val, v->r, med + 1, tr);
        }
        v->value += val;
    }
    int sum(int l, int r) { return sum(l, r, raiz, 0, 1e9 + 1); }
    int sum(int l, int r, node *v, int tl, int tr) {
        if (tl > r or tr < l) return 0;
        if (tl >= l and tr <= r) {
            return v->value;
        }
        int sx = 0;
        int med = (tl + tr) / 2;
        if (v->l != nullptr) {
            sx += sum(l, r, v->l, tl, med);
        }
        if (v->r != nullptr) {
            sx += sum(l, r, v->r, med + 1, tr);
        }
        return sx;
    }
};

//////////////////////

int n;
const int N = 1e18 + 1;
struct node {
    int *left = nullptr, *right = nullptr, val = 0, adl = 0, adr = 0;
};
node *raiz = new node();
void update(int pos, int val, node *v = raiz, int tl = 0, int tr = N) {
    if (tl == tr) {
        v->val += val;
        return;
    }
    int med = (tl + tr) / 2;
    if (pos <= med) {
        if (v->left == nullptr) {
            v->left = new node();
        }
        update(pos, val, v->left, tl, med);
    } else {
        if (v->right == nullptr) {
            v->right = new node();
        }
        update(pos, val, v->right, med + 1, tr);
    }
    v->val += val;
}
int sum(int l, int r, node *v = raiz, int tl = 0, int tr = N) {
    if (tr < l or tl > r) {
        return 0;
    }
    if (l >= tl and tr >= r) {
        return v->val;
    }
    int med = (tl + tr) / 2;
    int ans = 0;
    if (v->right != nullptr) ans = max(ans, sum(l, r, v->right, med + 1, tr));
    if (v->left != nullptr) ans = max(ans, sum(l, r, v->left, tl, med));
    return ans;
}
void updateR(int l, int r, int val, node *v = raiz, int tl = 0, int tr = N) {
    if (tl >= l and tr <= r) {
        v->val += (tr - tl + 1) * val;
        v->adl += val;
        v->adr += val;
        return;
    }
    int med = (tr + tl) / 2;
    if (l <= med) {
        if (v->left == nullptr) v->left = new node();
        updateR(l, r, val + v->adl, v->left, tl, med);
        v->adl = 0;
    }
    if (r >= med) {
        if (v->right == nullptr) {
            v->right = new node();
        }
        updateR(l, r, val + v->adr, v->right, med + 1, tr);
        v->adr = 0;
    }
}