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
const int N = 3e5 + 3;
string s, sRev;
int dp[N][2][2], n;
int go(int pos, bool rev, bool right) {
    if (pos == -1 or pos == n + 1) return 0;
    if ((pos == 0 and !right) or (pos == n and right)) return 1;
    int &x = dp[pos][rev][right];
    if (x != -1) return x;
    x = 1;
    if (right) {
        if (rev) {
            x += (s[pos] == 'L' ? go(pos + 1, !rev, 1) : 0);
        } else {
            x += (s[pos] == 'R' ? go(pos + 1, !rev, 1) : 0);
        }
    } else {
        if (rev) {
            x += (s[pos - 1] == 'R' ? go(pos - 1, !rev, 0) : 0);
        } else {
            x += (s[pos - 1] == 'L' ? go(pos - 1, !rev, 0) : 0);
        }
    }

    return x;
}
void solve() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    cin >> s;
    for (int i = 0; i <= n; i++) {
        cout << go(i, 0, 0) + go(i, 0, 1) - 1 << " ";
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
