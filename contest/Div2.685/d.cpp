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
// #define endl "\n"
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randint(const int l, const int r) {
    int sz = r - l + 1;
    return rng() % sz + l;
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
int n, a, b;
double dp[(int)3e6 + 1];
bool check[(int)1e6 + 1];
double go(int qt) {
    if (qt >= n) return 0;
    if (check[qt]) {
        return dp[qt];
    }
    check[qt] = true;
    double &x = dp[qt];
    if (a == 0) {
        x = (double)(b - a + 1) / (b - a);
        for (int i = a + 1; i <= b; i++) {
            x += go(qt + i) * 1.0 / (b - a);
        }
    } else {
        x = 1;
        for (int i = a; i <= b; i++) {
            x += go(qt + i) * 1.0 / (b - a + 1);
        }
    }
    return x;
}
void solve() {
    cin >> n >> a >> b;
    for (int i = n - 1; i >= 0; i--) {
        if (a == 0) {
            dp[i] = (double)(b - a + 1) / (b - a);
            dp[i] += (dp[i + a + 1] - dp[i + b + 1]) / (b - a);
        } else {
            dp[i] = 1;
            dp[i] += (dp[i + a] - dp[i + b + 1]) / (b - a + 1);
        }
        dp[i] += dp[i + 1];
    }
    cout << fixed << setprecision(5);
    cout << dp[0] - dp[1] << endl;
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
