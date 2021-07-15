#include <bits/stdc++.h>

using namespace std;
#define ll long long
const ll INF = 1e15;
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
//#define endl "\n"
#define fastio      \
    cin.tie(NULL);  \
    cout.tie(NULL); \
    ios_base::sync_with_stdio(false)
#define double long double
#define rep(i, n) for (int i = 0; i < (n); i++)
#define td(i) i.begin(), i.end()
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
const ll mod = 1e9 + 7;
// CHECAR SE PRECISA DE LONG LONG (ll)

void solve() {
    string s;
    map<string, double> wp;
    map<string, ll> wqtBody;
    map<string, ll> wqtTitle;
    map<string, ll> wqtAbstract;
    set<string> token;
    bool body = false;
    bool title = false;
    bool abstract = false;
    ll L = 0;
    bool achou = false;
    while (getline(cin, s)) {
        if (s[0] == '<' or s[0] == ' ') {
            achou = true;
        }
        string aux = "";
        if (!achou) {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == ';' or i == s.size() - 1) {
                    if (i == s.size() - 1) {
                        aux += s[i];
                    }
                    token.insert(aux);
                    aux = "";
                } else {
                    aux += s[i];
                }
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '>') {
                aux += s[i];
                if (aux == "<body>") {
                    body = true;
                } else if (aux == "</body>") {
                    body = false;
                } else if (aux == "<title>") {
                    title = true;
                } else if (aux == "</title>") {
                    title = false;
                } else if (aux == "<abstract>") {
                    abstract = true;
                } else if (aux == "</abstract>") {
                    abstract = false;
                }
                aux = "";
                continue;
            }
            string send = "";
            if (s[i] == '<') {
                if (aux.size() > 0) {
                    transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
                    send = aux;
                    aux = "";
                }
            }
            if (s[i] == ' ' or s[i] == '.' or s[i] == '!' or s[i] == '?' or
                s[i] == ',' or i == s.size()) {
                transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
                send = aux;
                aux = "";
            } else {
                aux += s[i];
            }
            if (send.size() < 4) {
                continue;
            }
            if (body) {
                wqtBody[send]++;
                L++;
            } else if (title) {
                wqtTitle[send]++;
                L++;
            } else if (abstract) {
                wqtAbstract[send]++;
                L++;
            }
        }
    }
    cout << L << endl;
    for (auto it : wqtBody) {
        wp[it.first] += it.second;
    }
    for (auto it : wqtTitle) {
        wp[it.first] += it.second * 5;
    }
    for (auto it : wqtAbstract) {
        wp[it.first] += it.second * 3;
    }
    cout << fixed << setprecision(6) << endl;
    int qt = 0;
    vector<pair<double, string> > final;
    for (auto it : wp) {
        // if (qt == 3) {
        //     break;
        // }
        final.pb(mp(it.second / L * 100, it.first));
    }
    sort(final.rbegin(), final.rend());
    for (auto it : final) {
        // if (qt == 3) {
        //     break;
        // }
        if (token.count(it.second)) {
            cout << it.second << ": " << it.first << endl;
            qt++;
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