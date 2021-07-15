bool achou;
int part = -1;
for (int j = 0; j < n; j++) {
    achou = false;
    for (int i = 0; i < m; i++) {
        if (d[v[i].b] > d[v[i].a] + v[i].c) {
            if (j == n - 1) part = v[i].b;
            d[v[i].b] = d[v[i].a] + v[i].c;
            p[v[i].b] = v[i].a;
            achou = true;
        }
    }
}
if (achou) {
    cout << "YES" << endl;
    vector<int> cycle;
    for (int i = 0; i < n; i++) {
        part = p[part];
    }
    for (int i = part;; i = p[i]) {
        cycle.pb(i);
        if (i == part and cycle.size() > 1) {
            break;
        }
    }
    reverse(cycle.begin(), cycle.end());
    for (int i = 0; i < cycle.size(); i++) {
        cout << cycle[i] << " ";
    }
    cout << endl;
} else {
    cout << "NO" << endl;
}
// fim