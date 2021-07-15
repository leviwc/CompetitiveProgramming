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
    if (n == 1) {
        cout << "! 1" << endl;
        cout.flush();
        return;
    }
    vector<int> v(n + 2, -1);
    v[0] = INF;
    v[n + 1] = INF;
    int l = 1, r = n;
    for (int i = 1; i <= 100; i++) {
        int m1;
        m1 = (l + l + r) / 3;
        if (v[m1] == -1) {
            cout << "? " << m1 << endl;
            cout.flush();
            cin >> v[m1];
        }
        if (v[m1 - 1] == -1) {
            cout << "? " << m1 - 1 << endl;
            cout.flush();
            cin >> v[m1 - 1];
        }
        if (v[m1 + 1] == -1) {
            cout << "? " << m1 + 1 << endl;
            cout.flush();
            cin >> v[m1 + 1];
        }
        if (v[m1] < v[m1 - 1] and v[m1] < v[m1 + 1]) {
            cout << "! " << m1 << endl;
            cout.flush();
            return;
        }
        if (v[m1] < v[m1 - 1]) {
            l = m1 + 1;
        } else {
            r = m1 - 1;
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
