const int N = 32 * 1e5;
struct node {
    int l = -1, r = -1, c = 0;
};
int at = 1;
vector<node> trie(N);
// q=valor adicionando na trie
// x=posição na trie
// no=altura na trie
// trie de bit
void add(int q, int x = 0, int no = 29) {
    if (no == -1) return;
    trie[x].c++;
    if (q >> no & 1) {
        if (trie[x].r == -1) {
            trie[x].r = at++;
        }
        add(q, trie[x].r, no - 1);
    } else {
        if (trie[x].l == -1) {
            trie[x].l = at++;
        }
        add(q, trie[x].l, no - 1);
    }
}
int dfs(int q, int x = 0, int no = 29) {
    if (no == -1) return 0;
    if ((q >> no & 1)) {
        if (trie[x].l != -1) {
            return dfs(q, trie[x].l, no - 1) + (1ll << no);
        } else {
            return dfs(q, trie[x].r, no - 1);
        }
    } else {
        if (trie[x].r != -1) {
            return dfs(q, trie[x].r, no - 1) + (1ll << no);
        } else {
            return dfs(q, trie[x].l, no - 1);
        }
    }
}

// trie de strings
struct node {
    int next[26];
    bool leaf = false;
    node() { fill(begin(next), end(next), -1); }
};
int at = 0;
vector<node> trie(1);
void addString(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }
    trie[v].leaf = true;
}