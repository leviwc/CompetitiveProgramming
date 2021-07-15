const int N = 2 * 1e5 + 1;
int n, q, l, timer;
vector<int> adj[N], tin(N), tout(N);
int dist[234567];  // para saber a distancia de 2 nos
int up[N][100];
void dfs(int pos, int pai) {
    tin[pos] = ++timer;
    dist[pos] = dist[pai] + 1;
    up[pos][0] = pai;
    for (int i = 1; i <= l; i++) {
        up[pos][i] = up[up[pos][i - 1]][i - 1];
    }
    for (int i : adj[pos])
        if (i != pai) dfs(i, pos);
    tout[pos] = ++timer;
}
bool is_anc(int u, int v) { return tin[u] <= tin[v] and tout[u] >= tout[v]; }
int lca(int u, int v) {
    if (is_anc(u, v)) {
        return u;
    }
    if (is_anc(v, u)) return v;
    for (int i = l; i >= 0; i--) {
        if (!is_anc(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}
int distancia(int u, int v) { return dist[u] + dist[v] - 2 * dist[lca(u, v)]; }
int goup(int a, int k) {
    for (int i = 0; i <= l; i++) {
        int dig = ((k >> i) & 1);
        if (dig) {
            a = up[a][i];
        }
    }
    return a;
}
// fim