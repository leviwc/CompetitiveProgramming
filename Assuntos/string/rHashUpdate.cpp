int m1 = 1e9 + 7;
int addi(int a, int b, int m) { return a + b - (a + b >= m ? m : 0); }
int mul(ll a, int b, int m) { return a * b % m; }
int sub(int a, int b, int m) { return a - b + (a - b < 0 ? m : 0); }
struct segTree {
    vector<int> vet;
    vector<int> t;
    vector<int> add;
    int m;
    int size;
    segTree() {}
    segTree(int size, vector<int> &vet, int m) {
        this->size = size;
        t.resize(4 * size);
        this->vet = vet;
        add.resize(4 * size);
        this->m = m;
        build(0, 0, size - 1);
    }
    ll merge(ll a, ll b) { return addi(a, b, m); }
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
        t[v] = addi(t[v], mul((tr - tl + 1), add[v], m), m);
        if (tl != tr) {
            add[2 * v + 1] = addi(add[2 * v + 1], add[v], m);
            add[2 * v + 2] = addi(add[2 * v + 2], add[v], m);
        }
        add[v] = 0;
    }
    ll rangeQuery(int l, int r, int v, int tl, int tr) {
        push(v, tl, tr);
        if (tr < l or tl > r) return 0;
        if (tl >= l and tr <= r) return t[v];
        int med = (tl + tr) / 2;
        return merge(rangeQuery(l, r, 2 * v + 1, tl, med),
                     rangeQuery(l, r, 2 * v + 2, med + 1, tr));
    }
    void update(int pos, ll value, int v, int tl, int tr) {
        push(v, tl, tr);
        if (tl > pos or tr < pos) return;
        if (tl == tr) {
            t[v] = addi(t[v], value, m);
            return;
        }
        int med = (tl + tr) / 2;
        update(pos, value, 2 * v + 1, tl, med);
        update(pos, value, 2 * v + 2, med + 1, tr);
        t[v] = merge(t[2 * v + 1], t[2 * v + 2]);
    }
    void updateRange(int l, int r, ll value, int v, int tl, int tr) {
        push(v, tl, tr);
        if (tr < l or tl > r) return;
        if (tl >= l and tr <= r) {
            add[v] = addi(add[v], value, m);
            push(v, tl, tr);
            return;
        }
        int med = (tl + tr) / 2;
        updateRange(l, r, value, 2 * v + 1, tl, med);
        updateRange(l, r, value, 2 * v + 2, med + 1, tr);
        t[v] = merge(t[2 * v + 1], t[2 * v + 2]);
    }

    ll posQuery(int pos, int v, int tl, int tr) {
        push(v, tl, tr);
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
    void update(int pos, ll value) { update(pos, value, 0, 0, size - 1); }
    ll rangeQuery(int l, int r) { return rangeQuery(l, r, 0, 0, size - 1); }
};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randint(const int l, const int r) {
    int sz = r - l + 1;
    return rng() % sz + l;
}
ll p = randint(31, 300);
vector<int> p1;
vector<int> preP1;
void prec() {
    p1.resize(1e5 + 1);
    preP1.resize(1e5 + 1);
    ll at = 1;
    for (int i = 0; i <= 1e5; i++) {
        p1[i] = at;
        at = (p * at) % m1;
        preP1[i] = (binpow(at, m1 - 2, m1));
    }
}
struct rHash {
    string s;
    pair<int, int> h;
    segTree preH1;
    rHash(){};
    rHash(const string &s) {
        ll at, at2, ans, ans2;
        at = at2 = 1;
        ans = ans2 = 0;
        vector<int> x(s.size());
        preH1 = segTree((int)s.size(), x, m1);
        for (int i = 0; i < s.size(); i++) {
            ans = (ans + ((s[i] - 'a' + 1) * (ll)p1[i]) % m1) % m1;
            preH1.update(i, ans);
        }
        this->h.first = ans;
        this->h.second = ans2;
        this->s = s;
    }
    pair<ll, ll> query(int l, int r) {
        ll at = preH1.posQuery(r);
        if (l != 0) {
            at -= preH1.posQuery(l - 1);
            if (at < 0) at += m1;
            at *= preP1[l - 1];
            at %= m1;
        }
        ll at2 = 0;
        return mp(at, at2);
    }
    void update(int pos, char c) {
        preH1.updateRange(pos, s.size() - 1,
                          sub(mul((c - 'a' + 1), p1[pos], m1),
                              mul((s[pos] - 'a' + 1), p1[pos], m1), m1));
        s[pos] = c;
    }
    bool comp(int l, int r, pair<ll, ll> hx) {
        pair<ll, ll> haux = query(l, r);
        return hx.first == haux.first and hx.second == haux.second;
    }
    bool comp(rHash &hx) { return comp(0, s.size() - 1, hx.h); }
};