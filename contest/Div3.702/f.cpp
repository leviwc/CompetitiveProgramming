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
int n;
vector<int> v;
map<int, int> m;
int check(int x) {
    int ans = 0;
    for (auto it : m) {
        if (it.second >= x) {
            ans += it.second - x;
        } else {
            ans += it.second;
        }
    }
    return ans;
}
void solve() {
    cin >> n;
    v.resize(n);
    m.clear();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        m[v[i]]++;
    }
    vector<int> vet;
    for (auto it : m) {
        vet.pb(it.second);
        ans += it.second;
    }
    sort(vet.begin(), vet.end());
    int men = ans;
    int qt = 0;
    int at = 0;
    for (int i = 1; i <= n; i++) {
        ans -= vet.size() - at;
        men = min(men, ans);
        while (at < vet.size() and vet[at] <= i) {
            ans += vet[at];
            at++;
        }
    }
    cout << men << endl;
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
