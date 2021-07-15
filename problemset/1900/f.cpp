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

// int gcd(int a, int b) {
//     while (b) {
//         a %= b;
//         swap(a, b);
//     }
//     return a;
// }
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
int l, r;
int n;
struct segTree {
    vector<ll> vet;
    vector<ll> t;
    int size;
    segTree(){};
    segTree(int size, vector<ll> &vet) {
        this->size = size;
        t.resize(4 * size);
        this->vet = vet;
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
    ll rangeQuery(int l, int r, int v, int tl, int tr) {
        if (tr < l or tl > r) return 0;
        if (tl >= l and tr <= r) return t[v];
        int med = (tl + tr) / 2;
        return merge(rangeQuery(l, r, 2 * v + 1, tl, med),
                     rangeQuery(l, r, 2 * v + 2, med + 1, tr));
    }
    void update(int pos, ll value, int v, int tl, int tr) {
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
    ll posQuery(int pos, int v, int tl, int tr) {
        if (tl > pos or tr < pos) return 0;
        if (tl == tr) {
            return t[v];
        }
        int med = (tl + tr) / 2;
        return merge(posQuery(pos, 2 * v + 1, tl, med),
                     posQuery(pos, 2 * v + 2, med + 1, tr));
    }
    ll posQuery(int pos) { return posQuery(pos, 0, 0, size - 1); }
    void update(int pos, ll value) { update(pos, value, 0, 0, size - 1); }
    ll rangeQuery(int l, int r) { return rangeQuery(l, r, 0, 0, size - 1); }
};
segTree seg;
const int N = 2e5;
int dp[N];
int go(int pos) {
    if (pos == n) {
        return INF;
    }
    int &x = dp[pos];
    if (x != -1) return x;
    if (n - pos < l) return -INF;
    x = -INF;
    for (int i = l; i <= r and pos + i <= n; i++) {
        x = max(x, min(seg.rangeQuery(pos, pos + i - 1), go(pos + i)));
    }
    return x;
}
void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> l >> r;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    seg = segTree(n, v);
    cout << go(0) << endl;
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
