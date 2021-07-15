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
    int n, m, k;
    cin >> n >> m >> k;
    int adj[n + 1][n + 1];
    int cor[n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    int at = 1;
    for (int i = 1; i <= n; i++) {
        int cornao[k + 1] = {0}, corsim[k + 1] = {0};
        corsim[cor[i]] = 1;
        for (int j = 1; j <= n; j++) {
            if (adj[i][j]) {
                corsim[cor[j]] = 1;
            } else {
                cornao[cor[j]] = 1;
            }
        }
        int minhacor = cor[i];
        int qt = 0;
        for (int j = 1; j <= k; j++) {
            if (corsim[j] and cornao[j]) {
                cout << -1 << endl;
                return;
            }
            qt += cornao[j];
            if (cornao[j] and minhacor == 0) {
                minhacor = j;
            }
        }
        if (minhacor == 0) {
            minhacor = at++;
        }
        cor[i] = minhacor;
        if (qt > 1) {
            cout << -1 << endl;
            return;
        }
        if (at > k + 1) {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << cor[i] << " ";
    }
    cout << endl;
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
