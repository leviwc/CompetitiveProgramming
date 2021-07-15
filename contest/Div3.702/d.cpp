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
int n;
vector<int> v;
vector<int> d;
void rec(int l, int r, int dd) {
    if (l > r) return;
    int mai = l;
    for (int i = l; i <= r; i++) {
        if (v[i] > v[mai]) mai = i;
    }
    d[mai] = dd;
    rec(l, mai - 1, dd + 1);
    rec(mai + 1, r, dd + 1);
}
void solve() {
    cin >> n;
    v.resize(n);
    d.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    rec(0, n - 1, 0);
    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
    cout << endl;
}
// revise as variaveis e a ordem nas funções
signed main() {
    // freopen("zeros.in", "r", stdin);
    // freopen("hidden.out", "w", stdout);
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
