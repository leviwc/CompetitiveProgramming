#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
vector<int> outro;
int main() {
    // vector:
    vector<int> vet;
    vet.push_back(23);  // forma de inserir
    vet.size();         // tamanho
    int n, m;
    cin >> n >> m;
    vector<int> v(n);             // declara com um tamanho fixo
    sort(v.begin(), v.end());     // ordena crescente
    sort(v.rbegin(), v.rend());   // ordena decrescente
    reverse(v.begin(), v.end());  // inverter o vetor
    outro.resize(n);              // mudar o tamanho para um tamanho fixo
    vector<int> menusUm(n, -1);   // inicializar com um valor fixo
    vector<vector<int> > mat(
        n, vector<int>(m, -1));  // inicializar uma matriz com vectors
    int valor;
    binary_search(v.begin(), v.end(),
                  valor);  // retorna verdadeiro ou falso se valor está no
                           // vector(precisa estar ordenado)
    // ponteiro
    // int *it;
    // *it = 23;
    // cout<<it<<endl; //posição na memoria
    // cout<<(*it)<<endl; //valor contido na variavel
    // lower bound upper bound
    // 1(v.begin()) 2 3 7 8 9 10 v.end()
    vector<int>::iterator it, it2;
    it = lower_bound(v.begin(), v.end(),
                     8);  // lower bound pega o primeiro numero maior ou igual
                          // ao numero pesquisado
    it2 = upper_bound(
        v.begin(), v.end(),
        8);  // upper bound pega o primeiro numero maior ao numero pesquisado
    it2++;
    cout << (*it2) << endl;
    it2--;
    int posição = it2 - v.begin();  // eu quero saber qual é a posição do it2
    // se eu quero o menor igual upperbound --
    if (it == v.end()) {
    } else {
        cout << (*it) << endl;
    }
    for (int i = 0; i < v.size(); i++) {
        v[i];
    }
    // set:
    set<int>
        s;  //é uma estrutura que se mantem ordenada e não aceita repetições
    set<int>::iterator it3;
    it3 = s.lower_bound(valor);
    it3 = s.upper_bound(valor);
    for (it3 = s.begin(); it3 != s.end(); it3++) {
        cout << (*it3) << endl;
    }
    s.count(13);
    multiset<int> s2;  // mesma coisa do set mas tem repetição
}