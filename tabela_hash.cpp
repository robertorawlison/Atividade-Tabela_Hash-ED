#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Tabela_Hash {
private:
    static const int tamanho_primeiro_nivel = 10;
    int tamanho_segundo_nivel;
    vector<vector<list<int>>> primeiro_nivel;
public:
    Tabela_Hash(int tamanho) {
        tamanho_segundo_nivel = (tamanho * 1.25) / 10;
        primeiro_nivel.resize(tamanho_primeiro_nivel);
    }
    // Função para inserir um valor na tabela hash

    void inserir(int valor){
        int idx_nivel1 =  valor/tamanho_primeiro_nivel;
        int idx_nivel2 = valor/tamanho_segundo_nivel;

        primeiro_nivel[idx_nivel1][idx_nivel2].push_back(valor);
    }
    // Função para remover um valor da tabela hash
    void remover(int valor){
        int idx_nivel1 = valor % tamanho_primeiro_nivel;
        int idx_nivel2 = valor % tamanho_segundo_nivel;

        primeiro_nivel[idx_nivel1][idx_nivel2].remove(valor);
    }

    void imprimir() {
        for (int i = 0; i < tamanho_primeiro_nivel; i++) {
            for (int j = 0; j < tamanho_segundo_nivel; j++) {
                std::cout << "Primeiro Nível: " << i << " Segundo Nível: " << j << " -> ";

                for (const auto& valor : primeiro_nivel[i][j]) {
                    std::cout << valor << " ";
                }
                std::cout << std::endl;
            }
        }
    }

};

int main(){
    Tabela_Hash tabela(100);

    tabela.inserir(5);
    tabela.inserir(15);
    tabela.inserir(25);
    tabela.inserir(7);
    tabela.inserir(17);

    tabela.imprimir();

    tabela.remover(25);
    tabela.remover(17);

    tabela.imprimir();

    return 0;
}