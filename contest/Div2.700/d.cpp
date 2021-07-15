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

void solve() {
    int n;
    cin >> n;
    stack<int> w, b;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[i] = a;
    }
    vector<int> novo;
    novo.pb(v[0]);
    bool achou = false;
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i - 1] and !achou) {
            achou = true;
            novo.pb(v[i]);
        } else if (v[i] != v[i - 1]) {
            achou = false;
            novo.pb(v[i]);
        }
    }
    vector<int> prox((int)novo.size());
    int at = -1;
    for (int i = (int)novo.size() - 1; i >= 0; i--) {
        prox[i] = at;
        if (i != (int)novo.size() - 1 and novo[i] == novo[i + 1]) {
            at = novo[i];
        }
    }
    for (int i = 0; i < novo.size(); i++) {
        if (w.empty()) {
            w.push(novo[i]);
            continue;
        }
        if (!w.empty() and w.top() == novo[i]) {
            if (b.empty() or b.top() != novo[i]) {
                b.push(novo[i]);
            }
            continue;
        }
        if (!w.empty() and w.top() != novo[i] and
            (b.empty() or b.top() == novo[i])) {
            w.push(novo[i]);
            continue;
        }
        if (b.top() == novo[i] and w.top() == novo[i]) {
            continue;
        }
        if (w.top() == prox[i]) {
            w.push(novo[i]);
        } else if (b.top() == prox[i]) {
            b.push(novo[i]);
        } else {
            w.push(novo[i]);
        }
    }
    cout << b.size() + w.size() << endl;
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
