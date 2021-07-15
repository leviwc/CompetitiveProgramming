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
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    vector<pair<int, int> > pre(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pre[i].first = v[i];
        if (i != 0) {
            pre[i].first += pre[i - 1].first;
        }
        pre[i].second = i;
    }
    int sum = pre[n - 1].first;
    pre[n] = mp(INF, n);
    sort(pre.begin(), pre.end());
    int men = INF;
    for (int i = n; i >= 0; i--) {
        men = min(men, pre[i].second);
        pre[i].second = men;
    }
    while (m--) {
        int x;
        cin >> x;
        if (sum <= 0) {
            auto it = lower_bound(pre.begin(), pre.end(), mp(x, (int)0));
            if ((*it).first == INF) {
                cout << -1 << " ";
            } else {
                cout << (*it).second << " ";
            }
        } else {
            int l = 0, r = 1e9;
            while (l <= r) {
                int med = (l + r) / 2;
                if (med > 0 and sum >= (x + med - 1) / med) {
                    r = med - 1;
                    continue;
                }
                auto it = lower_bound(td(pre), mp(x - (sum * med), (int)0));
                if ((*it).first != INF) {
                    r = med - 1;
                } else {
                    l = med + 1;
                }
            }
            cout << (r + 1) * (n) +
                        (*lower_bound(td(pre), mp(x - (sum * (r + 1)), (int)0)))
                            .second
                 << " ";
        }
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
