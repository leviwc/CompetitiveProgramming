void bfs(int v) {
    queue<int> q;
    q.push(v);
    dist[v] = 0;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (auto u : adj[v]) {
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
}