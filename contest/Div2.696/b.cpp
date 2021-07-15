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
const int mod = 1e9 + 7;
const int N = 1e6;
int small[N];
vector<int> primo;
void crivo() {
    for (int i = 2; i < N; i++) {
        if (small[i] == 0) {
            small[i] = i;
            primo.pb(i);
            for (int j = i + i; j < N; j += i) {
                if (small[j] == 0) small[j] = i;
            }
        }
    }
}
void solve() {
    int d;
    cin >> d;
    int ans = 1;
    int at = d + 1;
    ans *= *(lower_bound(td(primo), at));
    at = *(lower_bound(td(primo), at));
    at += d;
    ans *= *(lower_bound(td(primo), at));
    cout << ans << endl;
}
// revise as variaveis e a ordem nas funções
signed main() {
    // freopen("zeros.in", "r", stdin);
    // freopen("hidden.out", "w", stdout);
    fastio;
    int t = 1;
    crivo();
    cin >> t;
    while (t--) {
        solve();
    }
}