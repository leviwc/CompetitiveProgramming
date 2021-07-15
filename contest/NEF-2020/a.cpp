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
int func(int n) {
    int x = 1;
    while (n > x) {
        n -= x;
        x *= 2;
    }
    return x - n;
}
struct node {
    int l = 0, r = 0, val;
};
vector<node> v;
bool makeTree(int pos, int dois, int um) {
    node aux;
    if (dois > 0) {
        aux.val = 2;
        dois--;
    } else if (um > 0) {
        aux.val = 1;
        um--;
    } else {
        return false;
    }
    v.push_back(aux);
    int qual = 1;
    int vai = 0;
    if (dois % 2 != 0 and um > 0) {
        vai = 1;
        um--;
    }
    if (makeTree(pos + 1, (dois + 1) / 2, (um) / 2)) {
        v[pos].l = pos + 1;
        qual++;
    }
    qual = v.size();
    if (makeTree(qual, (dois) / 2, (um + 1) / 2 + vai)) {
        v[pos].r = qual;
        qual++;
    }
    return true;
}
void solve() {
    int um, dois;
    cin >> um >> dois;
    if (um < func(dois)) {
        cout << -1 << endl;
        return;
    }
    makeTree(0, dois, um);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].val << " " << v[i].l + (v[i].l != 0) << " "
             << v[i].r + (v[i].r != 0) << endl;
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
