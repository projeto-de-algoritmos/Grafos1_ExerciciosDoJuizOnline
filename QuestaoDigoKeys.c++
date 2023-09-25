#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        // Criar um vetor de conjuntos para armazenar as chaves de cada caixa
        vector<set<int>> chave(n + 1);

        // Ler as chaves para cada caixa, exceto a última
        for (int i = 1; i < n; i++) {
            int m;
            scanf("%d", &m);

            // Ler e armazenar as chaves da caixa atual
            while (m--) {
                int caixa;
                scanf("%d", &caixa);
                chave[i].insert(caixa);
            }
        }

        // Inicializar um vetor de pais para rastrear o caminho
        vector<int> pai(n + 1, -1);
        pai[1] = 0;

        // Criar uma fila para a travessia BFS
        queue<int> fila;
        fila.push(1);
        bool encontrado = false;

        // Executar a BFS
        while (!fila.empty()) {
            int k = fila.front();
            fila.pop();

            // Iterar pelas chaves da caixa atual
            for (int caixa_adjacente : chave[k]) {
                if (pai[caixa_adjacente] == -1) {
                    pai[caixa_adjacente] = k;

                    // Se encontrarmos a caixa de destino, definir 'encontrado' como verdadeiro
                    if (caixa_adjacente == n) {
                        encontrado = true;
                        break;
                    }

                    // Adicionar a caixa adjacente na fila
                    fila.push(caixa_adjacente);
                }
            }

            if (encontrado) {
                break;
            }
        }

        // Verificar se encontramos um caminho válido
        if (!encontrado) {
            printf("-1\n\n");
            continue;
        }

        // Reconstruir o caminho do destino para a origem
        vector<int> caminho;
        for (int i = n; i != 0; i = pai[i]) {
            caminho.push_back(i);
        }

        // Saída do comprimento do caminho e do próprio caminho
        printf("%d\n", caminho.size());
        for (int i = caminho.size() - 1; i >= 0; i--) {
            printf("%d ", caminho[i]);
        }
        printf("\n\n");
    }

    return 0;
}