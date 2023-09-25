#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

const int N = 100010;

// Define um tipo para representar uma aresta com índice
struct Edge {
    int v; // Vértice adjacente
    int index; // Índice da aresta
};

int main() {
    int n, k, d;
    cin >> n >> k >> d;

    vector<set<int>> ans(n - 1); // Conjunto de índices de arestas não importantes
    vector<bool> vis(n + 1, false); // Vetor de visitados
    vector<vector<Edge>> adj(n + 1); // Lista de adjacência com índices de arestas

    queue<int> q;

    // Ler os vértices iniciais marcados como importantes
    for (int i = 0; i < k; i++) {
        int m;
        cin >> m;
        q.push(m);
        vis[m] = true;
    }

    // Ler as arestas e construir a lista de adjacência
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        ans[i - 1].insert(i); // Inicialmente, todas as arestas são consideradas importantes
    }

    // Processar os vértices importantes
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (Edge edge : adj[u]) {
            int v = edge.v;
            int index = edge.index;

            if (!vis[v]) {
                vis[v] = true;
                ans[index - 1].clear(); // Remove a aresta da lista de arestas não importantes
                q.push(v);
            }
        }
    }

    cout << '\n';

    return 0;
}
