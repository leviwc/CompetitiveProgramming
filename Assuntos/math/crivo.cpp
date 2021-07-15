#include <bits/stdc++.h>

using namespace std;
#define int long long
#define INF 1ll << 60
#define pb push_back
#define mp make_pair
//#define endl "\n"
#define double long double
#define fastio      \
    cin.tie(NULL);  \
    cout.tie(NULL); \
    ios_base::sync_with_stdio(false)
const int mod = (1e9 + 7);
const int nonap = (1e9 - 5);
const int nonas = (1e9 * 2);

const int N = 1e6;
int small[N];
vector<int> primo;
void crivo() {
    for (int i = 2; i < N; i++) {
        if (small[i] == 0) {
            small[i] = i;
            primo.pb(i);
            for (int j = i + i; j < N; j += i) {
                if (small[j] == 0) small[j] = i;
            }
        }
    }
}
