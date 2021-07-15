#include <iostream>
#include <string>
using namespace std;

int main() {
    int n = 0, tam = 0, esp = 0, i = 0, j = 0, t = 0, k = 0;
    string nome;
    cin >> n;
    cin.ignore();
    // inicio do programa
    for (k = 0; k < n; k++) {
        getline(cin, nome);
        tam = nome.size();
        for (i = 0; i < tam; i++) {
            if (nome[i] == ' ') {
                esp++;
            }
        }
        // Formatação do nome
        if (esp == 0) {
            nome[0] = toupper(nome[0]);
            for (i = 0; i < tam; i++) {
                cout << nome[i];
            }
        } else {
            // FORMATAÇÃO DO NOME
            for (i = 0; i < tam; i++) {
                if (nome[i] == ' ' && t != esp) {
                    nome[j] = toupper(nome[j]);

                    nome[j + 1] = '.';

                    j = i + 1;
                    t++;
                }
            }
            nome[j] = toupper(nome[j]);
            t = 0;
            // Impressão do nome
            for (i = 0; i < tam; i++) {
                if (((nome[i] >= 'A' && nome[i] <= 'Z') || nome[i] == '.') &&
                    t != esp) {
                    cout << nome[i];
                    if (i == n - 1) continue;
                    if ((nome[i] == '.' && nome[i + 1] != ' ') ||
                        nome[i + 1] == ' ') {
                        cout << ' ';
                    }
                }
                if (nome[i] == ' ') {
                    t++;
                }
                if (nome[i] == '.') {
                    if (i == 0 or nome[i - 1] >= 'A' && nome[i - 1] <= 'Z') {
                        if (i == n - 1 or
                            nome[i + 1] >= 'A' && nome[i + 1] <= 'Z') {
                            t++;
                        }
                    }
                }
                if ()
                    if (t == esp) {
                        cout << nome[i + 1];
                    }
            }
        }
        cout << endl;
        // zerando os contadores
        j = 0;
        esp = 0;
        tam = 0;
        t = 0;
        i = 0;
    }
}