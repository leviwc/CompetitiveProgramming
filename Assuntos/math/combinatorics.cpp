// combinatoria / factorial / inv
const int N = 312345;
int fac[N];
int inv[N];
void factorial() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = i * fac[i - 1] % mod;
    }
    inv[N - 1] = binpow(fac[N - 1], mod - 2, mod);
    for (int i = N - 2; i >= 0; i--) {
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    }
}
int comb(int x, int i) { return fac[x] * inv[i] % mod * inv[x - i] % mod; }

// PENSAR EM COMBINATORIA COMO MULTIPLICAÇÃO DE POLINOMIOS ABAIXO:

// quantas formas existem de montar strings com A 0s e B 1s, K = A+B
// nCr(A+B, A) = nCr(A+B, B)

// cnt_x = qtd de algum tipo de sequencia de tamanho X
// cnt'_y = qtd de algum outro tipo de sequencia de tamanho Y = exemplo, se for
// seq de 1s

// X + Y = sequencia de 0s e 1s, com X 0s, Y 1s

// -------
// cnt_par[X] = qtd de sequencias corretas de parenteses de tamanho X
// cnt_col[Y] = qtd de sequencias corretas de colchetes de tamanho Y

// cnt_inter[Z] =
//   qtd de sequencias corretas de colchetes e de parenteses de tamanho Z,
//   que tem X parenteses, Y colchetes, ou seja, Z = X + Y

// -------
// nCr(X+Y, X) * cnt_x * cnt'_y

// cnt_inter[Z] = \sum_{X, Y} cnt_par[X] * cnt_col[Y], tq X+Y=Z

// for(int X = 0; X < n; X++) cnt_par[X] /= X!
// for(int Y = 0; Y < m; Y++) cnt_col[Y] /= Y!
// cnt_inter = multiply(cnt_par, cnt_col)
// for(int Z = 0; Z < n+m; Z++) cnt_inter[Z] *= Z!

// --------

// cnt[alpha][i] = qtd de sequencias compostas por caracteres alpha de tamanho i
// cnt[alpha][i] = 1 pra i <= qtd de alpha, 0 otherwise

// acc = Poly(1)
// for(int i = 0; i < 26; i++) {
//   acc *= cnt[i]
// }

// n*logn*log alpha