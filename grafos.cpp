#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n + 1);  // matriz de adjacencia.
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);  // se for bidirecional.
    }
    int c, b;
    cin >> c >> b;
    // busca em largura
    queue<int> q;
    q.push(c);
    int pai[n + 1];
    for (int i = 0; i <= n; i++) pai[i] = -1;
    pai[c] = c;
    while (!q.empty()) {
        int no = q.front();
        q.pop();
        if (no == b) {
            break;
        }
        for (int i = 0; i < adj[no].size(); i++) {
            if (pai[adj[no][i]] == -1) {
                q.push(adj[no][i]);
                pai[adj[no][i]] = no;
            }
        }
    }
    vector<int> caminho;
    int at = b;
    while (at != c) {
        caminho.push_back(at);
        at = pai[at];
    }
    caminho.push_back(c);
    reverse(caminho.begin(), caminho.end());
    for (int i = 0; i < caminho.size(); i++) {
        cout << caminho[i] << " ";
    }
    cout << endl;
}