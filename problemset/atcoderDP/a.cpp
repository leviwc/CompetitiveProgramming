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

void solve() {
    int n;
    cin >> n;
    vector<int> v(n), dp(n + 1, INF);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        if (i - 1 >= 0) {
            dp[i] = min(dp[i - 1] + abs(v[i - 1] - v[i]), dp[i]);
        }
        if (i - 2 >= 0) {
            dp[i] = min(dp[i - 2] + abs(v[i - 2] - v[i]), dp[i]);
        }
    }
    cout << dp[n - 1] << endl;
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
