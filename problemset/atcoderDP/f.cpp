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

void solve() {
    string s, t;
    cin >> s >> t;
    vector<vector<int> > dp((int)s.size(), vector<int>((int)t.size()));
    dp[0][0] = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < t.size(); j++) {
            if (s[i] == t[j]) {
                dp[i][j] =
                    max((i > 0 and j > 0 ? dp[i - 1][j - 1] : 0) + 1, dp[i][j]);
            }
            dp[i][j] = max((i > 0 ? dp[i - 1][j] : 0), dp[i][j]);
            dp[i][j] = max(dp[i][j], (j > 0 ? dp[i][j - 1] : 0));
        }
    }
    string ans = "";
    int i = s.size() - 1, j = t.size() - 1;
    while (i >= 0 and j >= 0) {
        int up, left, diag;
        up = (i > 0 ? dp[i - 1][j] : 0);
        left = (j > 0 ? dp[i][j - 1] : 0);
        diag = (i > 0 and j > 0 ? dp[i - 1][j - 1] : 0);
        if (dp[i][j] > up and dp[i][j] > left and dp[i][j] > diag) {
            ans += s[i];
            i--;
            j--;
        } else {
            if (up >= left) {
                i--;
            } else {
                j--;
            }
        }
    }
    reverse(td(ans));
    cout << ans << endl;
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
