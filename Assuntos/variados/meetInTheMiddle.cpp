
// separar em 2^n/2 e juntar com lower_bound
// LEMBRAR DE CASO BASE PRA N == 1
vector<ll> meet(int l, int r) {
    vector<ll> aux;
    int siz = (r - l + 1);
    for (ll i = 0; i < 1ll << siz; i++) {
        ll sum = 0;
        for (int j = 0; j < siz; j++) {
            if ((i >> j) & 1) {
                sum += v[l + j];
            }
        }
        aux.pb(sum);
    }
    sort(td(aux));
    return aux;
}