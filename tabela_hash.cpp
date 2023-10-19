#include <iostream>
#include <vector>
#include <list>

using namespace std;

//tabela hash duplamente encandeada

class tabela_h {
    static const int tamanho_level1 = 10;
    int tamanho_n;
    vector<vector<list<int>>> tabela;
public:
    tabela_h(int t){
    tamanho_n = t/10;
    tabela.resize(tamanho_level1);
    for (int i = 0; i < tamanho_level1; ++i) {
        tabela[i].resize(tamanho_n);
    }
}

    void inserir(int valor){
        int idx1 = valor % tamanho_level1;
        int idx2 = valor % tamanho_n;

        tabela[idx1][idx2].push_back(valor);
    }

    void remover(int valor){
        int idx1 = valor % tamanho_level1;
        int idx2 = valor % tamanho_n;

        tabela[idx1][idx2].remove(valor);
    }

    bool buscar(int valor){
        int idx1 = valor % tamanho_level1;
        int idx2 = valor % tamanho_n;

        for(const auto &val : tabela[idx1][idx2]){
            if(val == valor){
                return true;
            }
        }
        return false;
    }

    void imprimir(){
        for(int i = 0; i < tamanho_level1; i++){
            for(int j = 0; j < tamanho_n; j++){
                cout << "Posicao [" << i << "][" << j << "]: ";
                for(const auto &val : tabela[i][j]){
                    cout << val << " ";
                }
                cout << endl;
            }
        }
        cout << endl;
    }
};

int main(){
    tabela_h tabela(20);

    tabela.inserir(5);
    tabela.inserir(15);
    tabela.inserir(25);
    tabela.inserir(7);
    tabela.inserir(17);

    cout << "Buscando valor: 15" << endl;
    cout << "resultado busca: " << tabela.buscar(15) << endl;

    cout << "Tabela pos insercao: " << endl;
    tabela.imprimir();

    tabela.remover(25);
    tabela.remover(17);

    cout << "Tabela pos remocao: " << endl;
    tabela.imprimir();

    return 0;
}
