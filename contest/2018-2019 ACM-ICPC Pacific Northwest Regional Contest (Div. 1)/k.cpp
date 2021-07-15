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
const int N = 530;
double dpmai[N], dpmen[N];
double gomai(int at) {
    if (at == 0) {
        return 0;
    }
    double &x = dpmai[at];
    if (x != -1) {
        return x;
    }
    x = 0;
    for (int d1 = 1; d1 <= 6; d1++) {
        for (int d2 = 1; d2 <= 6; d2++) {
            double mai = -1;
            for (int i = 0; i < 1 << 9; i++) {
                bool achou = false;
                int sum = 0;
                for (int j = 0; j < 9; j++) {
                    if (i >> j & 1 and !(at >> j & 1)) {
                        achou = true;
                    }
                    if (i >> j & 1) {
                        sum += j + 1;
                    }
                }
                if (achou) continue;
                if (sum == d1 + d2) {
                    int aux = 0;
                    for (int j = 0; j < 9; j++) {
                        if (!(i >> j & 1) and at >> j & 1) {
                            aux += 1 << j;
                        }
                    }
                    mai = max(mai, 1.0 / 36.0 * gomai(aux));
                }
            }
            if (mai == -1) {
                int mul = 1;
                int sum = 0;
                for (int j = 8; j >= 0; j--) {
                    if (at >> j & 1) {
                        sum += mul * (j + 1);
                        mul *= 10;
                    }
                }
                x += sum * 1.0 / 36.0;
            } else {
                x += mai;
            }
        }
    }
    return x;
}
double gomen(int at) {
    if (at == 0) {
        return 0;
    }
    double &x = dpmen[at];
    if (x != -1) {
        return x;
    }
    x = 0;
    for (int d1 = 1; d1 <= 6; d1++) {
        for (int d2 = 1; d2 <= 6; d2++) {
            double men = INF;
            for (int i = 0; i < 1 << 9; i++) {
                bool achou = false;
                int sum = 0;
                for (int j = 0; j < 9; j++) {
                    if (i >> j & 1 and !(at >> j & 1)) {
                        achou = true;
                    }
                    if (i >> j & 1) {
                        sum += j + 1;
                    }
                }
                if (achou) continue;
                if (sum == d1 + d2) {
                    int aux = 0;
                    for (int j = 0; j < 9; j++) {
                        if (!(i >> j & 1) and at >> j & 1) {
                            aux += 1 << j;
                        }
                    }
                    men = min(men, 1.0 / 36.0 * gomen(aux));
                }
            }
            if (men == INF) {
                int mul = 1;
                int sum = 0;
                for (int j = 8; j >= 0; j--) {
                    if (at >> j & 1) {
                        sum += mul * (j + 1);
                        mul *= 10;
                    }
                }
                x += sum * 1.0 / 36.0;
            } else {
                x += men;
            }
        }
    }
    return x;
}
void solve() {
    for (int i = 0; i < 530; i++) {
        dpmai[i] = -1;
        dpmen[i] = -1;
    }
    string s;
    cin >> s;
    int d1, d2;
    cin >> d1 >> d2;
    int bb = 0;
    for (int i = 0; i < s.size(); i++) {
        int dig = s[i] - '0';
        dig--;
        bb += 1 << dig;
    }
    double ansmen = INF, ansmai = -1;
    int atmai, atmen;
    for (int i = 0; i < 1 << 9; i++) {
        bool achou = false;
        int sum = 0;
        for (int j = 0; j < 9; j++) {
            if (i >> j & 1 and !(bb >> j & 1)) {
                achou = true;
            }
            if (i >> j & 1) {
                sum += j + 1;
            }
        }
        if (achou) continue;
        if (sum == d1 + d2) {
            int aux = 0;
            for (int j = 0; j < 9; j++) {
                if (!(i >> j & 1) and bb >> j & 1) {
                    aux += 1 << j;
                }
            }
            if (gomai(aux) > ansmai) {
                ansmai = gomai(aux);
                atmai = i;
            }
            if (gomen(aux) < ansmen) {
                ansmen = gomen(aux);
                atmen = i;
            }
        }
    }
    if (ansmai == -1) {
        cout << -1 << " " << s << ".00000" << endl;
        cout << -1 << " " << s << ".00000" << endl;
        return;
    } else {
        cout << fixed << setprecision(5);
        int mul = 1;
        int sum = 0;
        for (int j = 8; j >= 0; j--) {
            if (atmen >> j & 1) {
                sum += mul * (j + 1);
                mul *= 10;
            }
        }
        cout << sum << " " << ansmen << endl;
        mul = 1;
        sum = 0;
        for (int j = 8; j >= 0; j--) {
            if (atmai >> j & 1) {
                sum += mul * (j + 1);
                mul *= 10;
            }
        }
        cout << sum << " " << ansmai << endl;
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
