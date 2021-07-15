#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e15 + 1;
//#define int long long
#define pb push_back
#define mp make_pair
//#define endl "\n"
#define fastio      \
    cin.tie(NULL);  \
    cout.tie(NULL); \
    ios_base::sync_with_stdio(false)
#define double long double
const double pi = acos(-1.0);
#define rep(i, n) for (int i = 0; i < (n); i++)
const int mod = 1e9 + 7;
// matrix exponentation: transformar dp o(1) memory em exponenciação de matriz
//
void add_self(ll& a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
}
ll mul(int a, int b) { return (ll)a * b % mod; }
struct M {
    vector<vector<ll> > t;
    int size;
    M(int size) {
        this->size = size;
        t.resize(size, vector<ll>(size));
    }
    M operator*(const M& b) const {
        M c = M(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    add_self(c.t[i][k], mul(t[i][j], b.t[j][k]));
                    // c.t[i][k]+= c.t[i][j] * b.t[j][k];
                }
            }
        }
        return c;
    }
    void matrixExpo(M a, ll k) {
        M result = M(a.t.size());
        rep(i, a.t.size()) result.t[i][i] = 1;
        while (k > 0) {
            if (k % 2 != 0) {
                result = result * a;
            }
            a = a * a;
            k /= 2;
        }
        t = result.t;
    }
};
