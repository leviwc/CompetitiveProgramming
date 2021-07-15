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
    int n, r;
    cin >> n >> r;
    vector<int> v(2 * n + 1);
    map<int, int> m;
    vector<int> check(n + 1);
    for (int i = 0; i < r - 1; i++) {
        int x, y, cx, cy;
        cin >> x >> y >> cx >> cy;
        if (cx == cy) {
            check[cx] = true;
        }
        if (v[x] == 0) {
            v[x] = cx;
            m[cx]++;
        }
        if (v[y] == 0) {
            m[cy]++;
            v[y] = cy;
        }
    }
    double mai = 0;
    double qt = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (v[i] == 0) qt++;
    }
    double maipoint = 0;
    double last = 0;
    for (int i = 1; i <= n; i++) {
        if (m[i] == 2) {
            if (check[i] == true) maipoint = i;
            if (check[i] == false) {
                last = i;
            }
        }
    }
    double dois = 0;
    double um = 0;
    double prob = 0;
    double at = 0;
    for (int i = maipoint + 1; i <= n; i++) {
        if (m[i] == 0) {
            prob += (2.0 / qt) * (1.0 / (qt - 1));
            dois += (2.0 / qt) * (1.0 / (qt - 1)) * (double)i;
            // at++;
        } else if (m[i] == 1) {
            um = (1.0 / qt) * (double)i + maipoint * ((qt - 1) / qt);
        }
    }
    // dois /= at
    dois += (1.0 - prob) * maipoint;
    cout << fixed << setprecision(7) << max(dois, max(um, max(maipoint, last)))
         << endl;
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
