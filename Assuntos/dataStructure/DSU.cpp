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
