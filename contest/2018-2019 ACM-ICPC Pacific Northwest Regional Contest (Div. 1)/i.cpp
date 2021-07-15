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
const int N = 1e5;
struct segTree {
    vector<ll> vet;
    vector<ll> t;
    int size;
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
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n), dif(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i > 0) {
            dif[i - 1] = abs(v[i] - v[i - 1]);
        }
    }
    segTree seg = segTree(n - 1, dif);
    while (q--) {
        int k, i, h;
        cin >> k >> i >> h, --i;
        if (k == 1) {
            v[i] = h;
            if (i < n - 1) {
                dif[i] = abs(v[i] - v[i + 1]);
                seg.update(i, dif[i]);
            }
            if (i - 1 >= 0) {
                dif[i - 1] = abs(v[i] - v[i - 1]);
                seg.update(i - 1, dif[i - 1]);
            }
        } else {
            int l = i, r = n - 2;
            int ans1 = -1, ans2 = -1;
            if (i != n - 1) {
                while (l <= r) {
                    int med = (l + r) / 2;
                    if (seg.rangeQuery(i, med) <= h) {
                        ans1 = med;
                        l = med + 1;
                    } else {
                        r = med - 1;
                    }
                }
            }
            l = 0, r = i - 1;
            if (i != 0) {
                while (l <= r) {
                    int med = (l + r) / 2;
                    if (seg.rangeQuery(med, i - 1) <= h) {
                        ans2 = med;
                        r = med - 1;
                    } else {
                        l = med + 1;
                    }
                }
            }
            int left = 0, right = 0;
            if (ans2 != -1) left = abs(i - 1 - ans2) + 1;
            if (ans1 != -1) right = abs(i - ans1) + 1;
            cout << left + right + 1 << endl;
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
