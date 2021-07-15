priority_queue<pii, vector<pii>, greater<pii> > q;
q.push({0, 0});
rep(i, N) dist[i] = INF;
dist[0] = 0;
while (!q.empty()) {
    auto [c, a] = q.top();
    q.pop();
    if (dist[a] != c) continue;
    for (auto [cost, b] : adj[a]) {
        if (c + cost < dist[b]) {
            dist[b] = c + cost;
            q.push({c + cost, b});
        }
    }
}
for (int i = 0; i < n; i++) {
    for (auto [cost, b] : adj[i]) {
        if (dist[b] == dist[i] + cost) {
            dag[i].pb(b);
        }
    }
}
// use a dijkstra to make shortest paths, then use only shortest paths edges to
// make a DAG