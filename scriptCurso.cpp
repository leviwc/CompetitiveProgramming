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
    string s;
    cout << "semestre: [" << endl;
    int n;
    cin >> n;
    cin.ignore();
    getline(cin, s);
    map<string, pair<int, int> > m;
    m["--"] = {-1, -1};
    for (int i = 1; i <= n; i++) {
        cout << "{numero: \"" << i << "\", materias: [" << endl;
        int j = 0;
        int auxxx = 0;
        while (getline(cin, s) and (s[0] != i + 1 + '0' and
                                    (i < 9 or s[1] != (i + 1) % 10 + '0'))) {
            if (auxxx != 0) {
                cout << "," << endl;
            }
            auxxx++;
            string nome = "", codigo = "";
            vector<pair<int, int> > dependencias;
            vector<string> palavras;
            string aux = "";
            for (int e = 0; e < s.size(); e++) {
                if (s[e] == ' ' or s[e] == ',') {
                    // cout << aux << endl;
                    if (aux != "") palavras.pb(aux);
                    aux = "";
                    continue;
                }
                aux += s[e];
            }
            if (aux != "") {
                palavras.pb(aux);
            }
            codigo = palavras[1];
            nome += palavras[2];
            for (int e = 3; e < palavras.size(); e++) {
                if (!m.count(palavras[e])) {
                    nome += " " + palavras[e];
                } else {
                    if (palavras[e] != "--") dependencias.pb(m[palavras[e]]);
                }
            }
            m[palavras[1]] = {j, i};
            cout << "{id: \"" << j << "\",codigo: \"" << codigo << "\",nome: \""
                 << nome << "\",passou:0,dependencias: [" << endl;
            for (int e = 0; e < dependencias.size(); e++) {
                cout << "{id:\"" << dependencias[e].first << "\",numero:\""
                     << dependencias[e].second << "\"}"
                     << (e == dependencias.size() - 1 ? "" : ",") << " ";
            }
            cout << endl;
            cout << "]}";

            j++;
        }
        /*
        {id: "0",codigo: "ENGF56",nome: "Introdução á engenharia de produção",
      passou:0,dependencias: [

      ]},
        */
        cout << "]}" << (i == n ? "" : ",") << endl;
        cout << endl;
    }
    cout << "]" << endl;
}
// revise as variaveis e a ordem nas funções
signed main() {
    // freopen("zeros.in", "r", stdin);
    // freopen("hidden.out", "w", stdout);
    // fastio;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
