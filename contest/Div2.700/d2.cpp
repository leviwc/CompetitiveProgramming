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
    vector<queue<int> > v(n + 1);
    vector<int> en(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        en[i] = a;
        v[a].push(i);
    }
    stack<int> w, b;
    for (int i = 0; i < n; i++) {
        v[en[i]].pop();
        if (w.empty()) {
            w.push(en[i]);
            continue;
        }
        if (w.top() == en[i]) {
            continue;
        }
        if (b.empty()) {
            b.push(en[i]);
            continue;
        }
        if (b.top() == en[i]) {
            continue;
        }
        if (v[w.top()].empty()) {
            w.push(en[i]);
            continue;
        }
        if (v[b.top()].empty()) {
            b.push(en[i]);
            continue;
        }
        if (v[w.top()].front() < v[b.top()].front()) {
            b.push(en[i]);
        } else {
            w.push(en[i]);
        }
    }
    cout << b.size() + w.size() << endl;
}
// revise as variaveis e a ordem nas fun????es
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
