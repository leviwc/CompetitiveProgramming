int n, m;
vector<int> adj[N], revAdj[N], component, order;
vector<int> c1;
bool check[N];
void dfs1(int u) {
    check[u] = true;
    for (int v : adj[u])
        if (!check[v]) dfs1(v);
    order.pb(u);
}
// memset check to 0!!
void dfs2(int u) {
    check[u] = true;
    component.pb(u);
    for (int v : revAdj[u])
        if (!check[v]) dfs2(v);
}