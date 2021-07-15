mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randint(const int l, const int r) {
    int sz = r - l + 1;
    return rng() % sz + l;
}
ll p = randint(31, 32);
struct rHash {
    int m1 = 1e9 + 7, m2 = 1e9 + 9;
    string s;
    pair<ll, ll> h;
    vector<ll> preH1;
    vector<ll> preP1;
    vector<ll> preH2;
    vector<ll> preP2;
    rHash(){};
    rHash(const string &s) {
        ll at, at2, ans, ans2;
        at = at2 = 1;
        ans = ans2 = 0;
        preH1.resize(s.size());
        preP1.resize(s.size());
        preH2.resize(s.size());
        preP2.resize(s.size());
        for (int i = 0; i < s.size(); i++) {
            ans = (ans + ((s[i] - 'a' + 1) * at) % m1) % m1;
            preH1[i] = ans;
            at = (p * at) % m1;
            preP1[i] = (binpow(at, m1 - 2, m1)) % m1;

            ans2 = (ans2 + ((s[i] - 'a' + 1) * at2) % m2) % m2;
            preH2[i] = ans2;
            at2 = (p * at2) % m2;
            preP2[i] = (binpow(at2, m2 - 2, m2)) % m2;
        }
        this->h.first = ans;
        this->h.second = ans2;
        this->s = s;
    }
    pair<ll, ll> query(int l, int r) {
        ll at = preH1[r];
        if (l != 0) {
            at -= preH1[l - 1];
            if (at < 0) at += m1;
            at *= preP1[l - 1];
            at %= m1;
        }
        ll at2 = preH2[r];
        if (l != 0) {
            at2 -= preH2[l - 1];
            if (at2 < 0) at2 += m2;
            at2 *= preP2[l - 1];
            at2 %= m2;
        }
        return mp(at, at2);
    }
    bool comp(int l, int r, pair<ll, ll> hx) {
        pair<ll, ll> haux = query(l, r);
        return hx.first == haux.first and hx.second == haux.second;
    }
    bool comp(rHash &hx) { return comp(0, s.size() - 1, hx.h); }
};