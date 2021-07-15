// minimum spanning tree
// uses dsu
const int N = 3 * 1e5 + 1;
int link[N];
int sz[N];
int find(int x) {
    if (link[x] == x) return x;
    return link[x] = find(link[x]);
}
bool same(int x, int y) { return find(x) == find(y); }
void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    link[b] = a;
    sz[a] += sz[b];
}
// edge a->b cost c:
struct edge {
    int a, b, c;
};
vector<edge> edges;
vector<pair<int, int>> adj[N];
bool cmp(edge u, edge v) { return (u.c < v.c); }
void kruskal() {
    sort(edges.begin(), edges.end(), cmp);
    for (int i = 0; i < edges.size(); i++) {
        if (!same(edges[i].a, edges[i].b)) {
            unite(edges[i].a, edges[i].b);
            adj[edges[i].a].pb(mp(edges[i].b, edges[i].c));
            adj[edges[i].b].pb(mp(edges[i].a, edges[i].c));
        }
    }
}
// fim