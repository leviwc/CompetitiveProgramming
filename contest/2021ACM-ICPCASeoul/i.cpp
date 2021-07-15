#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll INF = 2e18;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size();
#define endl "\n"
#define fastio      \
    cin.tie(NULL);  \
    cout.tie(NULL); \
    ios_base::sync_with_stdio(false)
#define double long double
#define rep(i, x, n) for (int i = x; i < (n); i++)
#define td(i) i.begin(), i.end()
#define rtd(i) i.rbegin(), i.rend()

const double e = exp(1);
const double pi = acos(-1.0);

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }

long long binpows(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)  // impar
            res = res * a;
        a = a * a;
        b >>= 1;  // /2
    }
    return res;
}
ll binpow(ll a, ll b, ll m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
struct segTree {
    vector<ll> vet;
    vector<ll> t;
    vector<ll> add;
    int size;
    segTree(int size, vector<ll> &vet) {
        this->size = size;
        t.resize(4 * size);
        this->vet = vet;
        add.resize(4 * size);
        build(0, 0, size - 1);
    }
    ll merge(ll a, ll b) { return max(a, b); }
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
        t[v] += add[v];
        if (tl != tr) {
            add[2 * v + 1] += add[v];
            add[2 * v + 2] += add[v];
        }
        add[v] = 0;
    }
    ll rangeQuery(int l, int r, int v, int tl, int tr) {
        push(v, tl, tr);
        if (tr < l or tl > r) return -INF;
        if (tl >= l and tr <= r) return t[v];
        int med = (tl + tr) / 2;
        return merge(rangeQuery(l, r, 2 * v + 1, tl, med),
                     rangeQuery(l, r, 2 * v + 2, med + 1, tr));
    }
    void update(int pos, ll value, int v, int tl, int tr) {
        push(v, tl, tr);
        if (tl > pos or tr < pos) return;
        if (tl == tr) {
            t[v] = value;
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
            add[v] += value;
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
        if (tl > pos or tr < pos) return -INF;
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
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n), pre(n + 1);
    vector<tuple<int, int, int, int> > query(m);
    priority_queue<pair<int, int>, vector<pair<int, int> >,
                   greater<pair<int, int> > >
        q;
    vector<int> answer(m);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pre[i + 1] = v[i];
        pre[i + 1] += pre[i];
        q.push({pre[i], i});
    }
    for (int i = 0; i < m; i++) {
        int l, r, u;
        cin >> l >> r >> u;
        u += pre[l - 1];
        query[i] = {u, l, r, i};
    }
    sort(query.begin(), query.end());
    vector<int> toseg(n + 1, -INF);
    segTree seg = segTree(n + 1, toseg);
    for (int i = 0; i <= n; i++) {
        cout << seg.posQuery(i) << " ";
    }
    cout << endl << endl;
    for (int i = 0; i < m; i++) {
        auto [a, b, c, j] = query[i];
        cout << a << endl;
        while (!q.empty() and a >= q.top().first) {
            seg.update(q.top().second + 1, q.top().first);
            q.pop();
        }
        for (int i = 0; i <= n; i++) {
            cout << seg.posQuery(i) << " ";
        }
        cout << endl << endl;
        int aux = seg.rangeQuery(b, c);
        if (aux == -INF) {
            answer[j] = -INF;
        } else {
            answer[j] = aux - pre[b - 1];
        }
    }
    for (int i = 0; i < m; i++) {
        if (answer[i] == -INF) {
            cout << "NONE" << endl;
        } else {
            cout << answer[i] << endl;
        }
    }
}
// revise as variaveis e a ordem nas funções
signed main() {
    // freopen("zeros.in", "r", stdin);
    // freopen("hidden.out", "w", stdout);
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
