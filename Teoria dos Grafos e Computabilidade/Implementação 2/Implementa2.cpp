#include <iostream> 
#include <vector>
#include <cmath>

using namespace std;

// Funcao para imprimir o conjunto de vertices
void printVertices(const vector<int>& vertices) {
    cout << "Vertices: { ";
    for (size_t i = 0; i < vertices.size(); ++i) {
        cout << vertices[i];
        if (i < vertices.size() - 1) cout << ", ";
    }
    cout << " }";
}

// Funcao para imprimir o conjunto de arestas
void printArestas(const vector<pair<int, int>>& edges) {
    if (edges.empty()) {
        cout << " Arestas: { }";
        return;
    }
    cout << " Arestas: { ";
    for (size_t i = 0; i < edges.size(); ++i) {
        cout << "(" << edges[i].first << ", " << edges[i].second << ")";
        if (i < edges.size() - 1) cout << ", ";
    }
    cout << " }";
}

// Funcao para gerar todos os subgrafos
void gerarSubgrafos(int n) {
    int totalSubgrafos = 0;
    int vertexSubsets = pow(2, n);

    // Itera por todos os subconjuntos de vertices (excluindo o conjunto vazio)
    for (int vertice_masc = 1; vertice_masc < vertexSubsets; ++vertice_masc) {
        vector<int> vertices;

        // Identifica quais vertices estao no subconjunto atual
        for (int i = 0; i < n; ++i) {
            if (vertice_masc & (1 << i)) {
                vertices.push_back(i + 1);
            }
        }

        int k = vertices.size();
        int totalArestasPossivel = k * (k - 1) / 2;
        int totalEdgeSubsets = pow(2, totalArestasPossivel);

        // Mapeia cada par de vertices para uma posicao para geracao de arestas
        vector<pair<int, int>> possiveisAresta;
        for (int i = 0; i < k; ++i) {
            for (int j = i + 1; j < k; ++j) {
                possiveisAresta.push_back({vertices[i], vertices[j]});
            }
        }

        // Itera por todos os subconjuntos de arestas
        for (int e_mask = 0; e_mask < totalEdgeSubsets; ++e_mask) {
            vector<pair<int, int>> edges;

            for (int idx = 0; idx < totalArestasPossivel; ++idx) {
                if (e_mask & (1 << idx)) {
                    edges.push_back(possiveisAresta[idx]);
                }
            }

            // Exibe o subgrafo atual
            printVertices(vertices);
            printArestas(edges);
            cout << endl;
            totalSubgrafos++;
        }
    }

    cout << "\nNumero total de subgrafos gerados: " << totalSubgrafos << endl;
}

int main() {
    int n;

    cout << "Informe o numero de vertices do grafo completo: ";
    cin >> n;

    if (n <= 0) {
        cout << "O numero de vertices deve ser maior que 0." << endl;
        return 1;
    }

    gerarSubgrafos(n);

    return 0;
}
