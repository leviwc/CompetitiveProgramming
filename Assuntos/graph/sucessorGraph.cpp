// distance queries in a sucessor graph

const int N = 2e5 + 1;
int n, q, d[N], rt[N], rp[N], t[N], tin[N], cr[N], tout[N], dt, cs[N];
// rt == root,
bool check[N];
vector<int> adj[N], cyc;
void dfs1(int u) {
    tin[u] = dt++;
    for (int v : adj[u]) {
        if (rt[v] != v) {
            d[v] = d[u] + 1;
            rt[v] = rt[u];
            cr[v] = cr[u];
            dfs1(v);
        }
    }
    tout[u] = dt;
}
void solve() {
    cin >> n >> q;
    vector<int> v(n);
    rep(i, n) {
        cin >> t[i], --t[i];
        adj[t[i]].pb(i);
    }
    memset(rt, -1, sizeof(rt));
    for (int i = 0; i < n; i++) {
        if (rt[i] != -1) continue;
        int u = i;
        while (!check[u]) {
            check[u] = 1;
            u = t[u];
        }
        while (!cyc.size() or u != cyc[0]) {
            check[u] = true;
            rp[u] = cyc.size();
            cyc.pb(u);
            cr[u] = i;
            rt[u] = u;
            u = t[u];
        }
        for (int ci : cyc) {
            dt = 0, dfs1(ci), cs[ci] = cyc.size();
        }
        cyc.clear();
    }

    while (q--) {
        int a, b;
        cin >> a >> b, --a, --b;
        int ans = -1;
        if (cr[a] == cr[b]) {
            if (rt[b] == b) {
                ans = d[a];
                a = rt[a];
                ans += (rp[b] - rp[a] + cs[a]) % cs[a];
            } else {
                if (rt[a] == rt[b] and tin[b] <= tin[a] and tin[a] < tout[b]) {
                    ans = d[a] - d[b];
                }
            }
        }
        cout << ans << endl;
    }
}