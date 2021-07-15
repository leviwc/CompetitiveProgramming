#include <bits/stdc++.h>

using namespace std;
#define ll long long
const ll INF = 1e18 + 1;
//#define int long long
#define pb push_back
#define mp make_pair
// #define endl "\n"
#define fastio      \
    cin.tie(NULL);  \
    cout.tie(NULL); \
    ios_base::sync_with_stdio(false)
#define double long double
#define rep(i, n) for (int i = 0; i < (n); i++)
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
const ll mod = 1e9 + 7;
// CHECAR SE PRECISA DE LONG LONG (ll)
struct segTree {
    vector<double> vet;
    vector<double> t;
    vector<double> add;
    int size;
    segTree(int size, vector<double> &vet) {
        this->size = size;
        t.resize(4 * size);
        this->vet = vet;
        add.resize(4 * size);
        build(0, 0, size - 1);
    }
    double merge(double a, double b) { return a + b; }
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

    double rangeQuery(int l, int r, int v, int tl, int tr) {
        if (tr < l or tl > r) return 0;
        if (tl >= l and tr <= r) return t[v];
        int med = (tl + tr) / 2;
        return merge(rangeQuery(l, r, 2 * v + 1, tl, med),
                     rangeQuery(l, r, 2 * v + 2, med + 1, tr));
    }
    void update(int pos, double value, int v, int tl, int tr) {
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
    void push(int v, int tl, int tr) {
        t[v] += add[v];
        if (tl != tr) {
            add[2 * v + 1] += add[v];
            add[2 * v + 2] += add[v];
        }
        add[v] = 0;
    }
    void updateRange(int l, int r, double value, int v, int tl, int tr) {
        if (tr < l or tl > r) return;
        push(v, tl, tr);
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
    double posQuery(int pos, int v, int tl, int tr) {
        push(v, tl, tr);
        if (tl > pos or tr < pos) return 0;
        if (tl == tr) {
            return t[v];
        }
        int med = (tl + tr) / 2;
        return merge(posQuery(pos, 2 * v + 1, tl, med),
                     posQuery(pos, 2 * v + 2, med + 1, tr));
    }
};
const int N = 3e5 + 1;

int n;
vector<double> v;
vector<int> adj[N];
vector<int> tin(N), tout(N);
int timer;
void dfs(int pos, int pai) {
    v.pb(logl(1));
    tin[pos] = timer++;
    for (auto it : adj[pos]) {
        if (it != pai) {
            dfs(it, pos);
        }
    }
    tout[pos] = timer;
}

void solve() {
    double comp = logl(1e9);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].pb(b - 1);
        adj[b - 1].pb(a - 1);
    }
    dfs(0, 0);
    segTree seg = segTree(n, v);
    int q;
    cin >> q;
    cout << fixed << setprecision(6);
    while (q--) {
        double t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            double val = logl(y);
            x--;
            seg.update(tin[x], val - v[tin[x]], 0, 0, n - 1);
            v[tin[x]] = val;
        } else {
            double a, b;
            x--;
            y--;
            a = seg.rangeQuery(tin[x], tout[x] - 1, 0, 0, n - 1);
            b = seg.rangeQuery(tin[y], tout[y] - 1, 0, 0, n - 1);
            a -= b;

            if (a >= comp) {
                cout << 1e9 << endl;
            } else {
                cout << powl(e, a) << endl;
            }
        }
    }
}
// revise as variaveis e a ordem nas funções
signed main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}