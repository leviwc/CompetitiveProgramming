
struct segTree {
    vector<ll> vet;
    vector<ll> t;
    vector<ll> add;
    vector<ll> same;
    int size;
    segTree(int size, vector<ll> &vet) {
        this->size = size;
        t.resize(4 * size);
        this->vet = vet;
        add.resize(4 * size);
        same.assign(4 * size, -1);
        build(0, 0, size - 1);
    }
    ll merge(ll a, ll b) { return a + b; }
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = vet[tl];
            return;
        }
        int med = (tl + tr) / 2;
        build(2 * v + 1, tl, med);
        build(2 * v + 2, med + 1, tr);
        t[v] = merge(t[2 * v + 1], t[2 * v + 2]);
    }
    void push(int v, int tl, int tr) {
        if (same[v] != -1) {
            same[v] += add[v];
            add[v] = 0;
            return;
        }
        t[v] += (tr - tl + 1) * add[v];
        if (tl != tr) {
            add[2 * v + 1] += add[v];
            add[2 * v + 2] += add[v];
        }
        add[v] = 0;
    }
    void push2(int v, int tl, int tr) {
        if (same[v] != -1) t[v] = (tr - tl + 1) * same[v];
        if (same[v] != -1 and tl != tr) {
            same[2 * v + 1] = same[v];
            same[2 * v + 2] = same[v];
            add[2 * v + 1] = 0;
            add[2 * v + 2] = 0;
            same[v] = -1;
        }
    }
    ll rangeQuery(int l, int r, int v, int tl, int tr) {
        push(v, tl, tr);
        push2(v, tl, tr);
        if (tr < l or tl > r) return 0;
        if (tl >= l and tr <= r) return t[v];
        int med = (tl + tr) / 2;
        return merge(rangeQuery(l, r, 2 * v + 1, tl, med),
                     rangeQuery(l, r, 2 * v + 2, med + 1, tr));
    }
    void update(int pos, ll value, int v, int tl, int tr) {
        push(v, tl, tr);
        push2(v, tl, tr);
        if (tl > pos or tr < pos) return;
        if (tl == tr) {
            t[v] += value;
            return;
        }
        int med = (tl + tr) / 2;
        update(pos, value, 2 * v + 1, tl, med);
        update(pos, value, 2 * v + 2, med + 1, tr);
        t[v] = merge(t[2 * v + 1], t[2 * v + 2]);
    }
    void updateRange(int l, int r, ll value, int v, int tl, int tr) {
        push(v, tl, tr);
        push2(v, tl, tr);
        if (tr < l or tl > r) return;
        if (tl >= l and tr <= r) {
            add[v] += value;
            push(v, tl, tr);
            push2(v, tl, tr);
            return;
        }
        int med = (tl + tr) / 2;
        updateRange(l, r, value, 2 * v + 1, tl, med);
        updateRange(l, r, value, 2 * v + 2, med + 1, tr);
        t[v] = merge(t[2 * v + 1], t[2 * v + 2]);
    }
    void setRange(int l, int r, ll value, int v, int tl, int tr) {
        push(v, tl, tr);
        push2(v, tl, tr);
        if (tr < l or tl > r) return;
        if (tl >= l and tr <= r) {
            same[v] = value;
            push2(v, tl, tr);
            return;
        }
        int med = (tl + tr) / 2;
        setRange(l, r, value, 2 * v + 1, tl, med);
        setRange(l, r, value, 2 * v + 2, med + 1, tr);
        t[v] = merge(t[2 * v + 1], t[2 * v + 2]);
    }
    ll posQuery(int pos, int v, int tl, int tr) {
        push(v, tl, tr);
        push2(v, tl, tr);
        if (tl > pos or tr < pos) return 0;
        if (tl == tr) {
            return t[v];
        }
        int med = (tl + tr) / 2;
        return merge(posQuery(pos, 2 * v + 1, tl, med),
                     posQuery(pos, 2 * v + 2, med + 1, tr));
    }
    ll posQuery(int pos) { return posQuery(pos, 0, 0, size - 1); }
    void updateRange(int l, int r, ll value) {
        updateRange(l, r, value, 0, 0, size - 1);
    }
    void setRange(int l, int r, ll value) {
        setRange(l, r, value, 0, 0, size - 1);
    }
    void update(int pos, ll value) { update(pos, value, 0, 0, size - 1); }
    ll rangeQuery(int l, int r) { return rangeQuery(l, r, 0, 0, size - 1); }
};