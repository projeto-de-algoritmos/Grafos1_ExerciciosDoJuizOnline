#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int main() {
    int casos;
    cin >> casos; // Lê o número de casos a serem processados

    while (casos--) {
        int n;
        cin >> n; // Lê o número de caixas

        vector<set<int>> chaves(n + 1); // Cria um vetor de conjuntos para armazenar as chaves de cada caixa

        for (int i = 1; i < n; i++) {
            int m;
            cin >> m; // Lê o número de chaves disponíveis para a caixa 'i'

            while (m--) {
                int caixa;
                cin >> caixa; // Lê o número da caixa que a chave abre e a adiciona ao conjunto de chaves
                chaves[i].insert(caixa);
            }
        }

        vector<int> pai(n + 1, -1); // Cria um vetor para rastrear os pais de cada caixa no caminho
        pai[1] = 0; // Define o pai da primeira caixa como 0 (raiz)
        queue<pair<int, int>> fila; // Cria uma fila para realizar a busca em largura
        fila.push(make_pair(1, 1)); // Adiciona a primeira caixa à fila com a profundidade 1
        bool resultado = false; // Variável para verificar se encontrou o caminho até a última caixa

        while (!fila.empty()) {
            set<int>::iterator it;
            int k = fila.front().first; // Caixa atual
            int caixa = fila.front().second; // Profundidade atual
            fila.pop(); // Remove a caixa da fila

            for (it = chaves[k].begin(); it != chaves[k].end(); it++) {
                int nova_caixa = *it; // Próxima caixa a ser explorada

                if (pai[nova_caixa] == -1) {
                    pai[nova_caixa] = k; // Define o pai da próxima caixa
                    if (nova_caixa == n) { // Se chegou à última caixa, define o resultado como verdadeiro
                        resultado = true;
                        break;
                    }
                    fila.push(make_pair(nova_caixa, caixa + 1)); // Adiciona a próxima caixa à fila com profundidade incrementada
                }
            }

            if (resultado)
                break; // Se já encontrou o caminho, encerra o loop
        }

        if (!resultado) {
            cout << "-1" << endl << endl; // Se não encontrou o caminho, imprime -1
            continue; // Passa para o próximo caso
        }

        vector<int> resultado_final;
        for (int i = pai[n]; i != 0; i = pai[i])
            resultado_final.push_back(i); // Constrói o caminho reverso, do último pai até o primeiro

        cout << resultado_final.size() << endl; // Imprime o tamanho do caminho

        for (int i = resultado_final.size() - 1; i >= 0; i--)
            cout << resultado_final[i] << " "; // Imprime o caminho reverso

        cout << endl << endl;
    }

    return 0;
}
