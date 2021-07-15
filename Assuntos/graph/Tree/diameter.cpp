// aux.first é o diametro da arvore
vector<int> adj[234566];
pair<int, int> dfs(int pos, int pai) {
    if (adj[pos].size() == 1 and pos != pai) {
        return mp(0, pos);
    }
    pair<int, int> dist = mp(0, 0);
    for (auto i : adj[pos]) {
        if (i != pai) {
            auto aux = dfs(i, pos);
            if (dist.first < aux.first + 1) {
                dist = aux;
                dist.first++;
            }
        }
    }
    return dist;
}
pair<int, int> aux = dfs(1, 1);
aux = dfs(aux.second, aux.second);
cout << aux.first << endl;
//