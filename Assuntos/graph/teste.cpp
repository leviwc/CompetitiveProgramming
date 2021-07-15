#include <bits/stdc++.h>
 
using namespace std;
#define int long long
const int INF=1e15;
#define pb push_back
#define mp make_pair
#define endl "\n"
#define double long double
#define fastio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false)
 
int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}
long long binpows(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)  //impar
            res = res * a;
        a = a * a;
        b >>= 1;  // /2
    }
    return res;
}
int binpow(int a, int b, int m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


void solve(){
	cout<<100000<<endl;
    for(int i=1; i<=100000; i++){
        cout<<i<<endl;
    }
}
 
signed main(){fastio;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}