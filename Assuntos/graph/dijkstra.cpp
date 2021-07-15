const int N = 3 * 1e5 + 1;
vector<pair<int, int> > adj[N];
vector<int> d(N);
int n;
// vector<int> to(N);
void dij(int v) {
    priority_queue<pii, vector<pii>, greater<pii> > q;
    rep(i, n + 1) d[i] = INF;
    q.push({0, v});
    d[v] = 0;
    while (!q.empty()) {
        auto [u, v] = q.top();
        q.pop();
        if (d[v] != u) continue;
        for (auto [b, c] : adj[v]) {
            if (d[b] > u + c) {
                d[b] = u + c;
                // to[b] = v;
                q.push({d[b], b});
            }
        }
    }
}