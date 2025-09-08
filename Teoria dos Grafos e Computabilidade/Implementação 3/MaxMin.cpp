#include <iostream>
#include <vector>
#include <climits> // Para usar INT_MAX como infinito
#include <algorithm> // Para usar reverse
#include <queue> // Para usar fila de prioridade

using namespace std;

struct Aresta {
    int destino, peso;
};

struct Vertice {
    int dist = INT_MIN; // Inicialmente a menor distância é menos infinito
    int antecessor = -1; // Antecessor inicial é indefinido
};

void mostrarCaminho(int destino, int origem, const vector<Vertice>& vertices) {
    if (vertices[destino].dist == INT_MIN) {
        cout << "Não há caminho de " << origem << " para " << destino << endl;
    } else {
        vector<int> caminho;
        for (int v = destino; v != -1; v = vertices[v].antecessor) {
            caminho.push_back(v);
        }
        reverse(caminho.begin(), caminho.end());

        cout << "Caminho de " << origem << " para " << destino << ": ";
        for (size_t i = 0; i < caminho.size(); i++) {
            cout << caminho[i];
            if (i < caminho.size() - 1) cout << " -> ";
        }
        cout << " | Peso da menor aresta: " << vertices[destino].dist << endl;
    }
}

void maxMin(int n, int origem, vector<vector<Aresta>>& grafo, vector<Vertice>& vertices) {
    // Inicializa a distância do vértice de origem
    vertices[origem].dist = INT_MAX; // Máximo inicialmente

    // Usamos uma fila de prioridade para selecionar a aresta com o maior peso
    priority_queue<pair<int, int>> pq; // par (peso, vértice)
    pq.push({INT_MAX, origem}); // Começamos com a origem

    while (!pq.empty()) {
        auto [peso, u] = pq.top(); // Pega o maior peso
        pq.pop();

        // Se a distância do vértice atual é menor que a já registrada, ignoramos
        if (vertices[u].dist > peso) continue;

        // Atualiza as distâncias acumuladas dos vizinhos de u
        for (const Aresta& vizinho : grafo[u]) {
            int novaDist = min(vertices[u].dist, vizinho.peso);
            // Se encontramos um caminho com um peso maior
            if (novaDist > vertices[vizinho.destino].dist) {
                vertices[vizinho.destino].dist = novaDist;
                vertices[vizinho.destino].antecessor = u; // Atualiza o antecessor
                pq.push({novaDist, vizinho.destino}); // Adiciona à fila de prioridade
            }
        }
    }

    // Mostra os caminhos para todos os vértices
    for (int i = 0; i < n; i++) {
        if(i == origem)
            continue;
        mostrarCaminho(i, origem, vertices);
    }
}

int main() {
    int n = 5; // Número de vértices

    vector<Vertice> vertices(n); // Vetor que armazena informações de cada vértice

    vector<vector<Aresta>> grafo(n); // o grafo é um vetor de inteiros (vértices), onde cada vértice possui um vetor de arestas

    // Adiciona as arestas ao grafo (Exemplo de grafo)
    grafo[0].push_back({1, 4});
    grafo[0].push_back({2, 3});
    grafo[1].push_back({2, 5});
    grafo[1].push_back({3, 2});
    grafo[2].push_back({4, 3});
    grafo[2].push_back({3, 1});
    grafo[3].push_back({4, 4});

    int origem = 0; // Vértice inicial (origem)

    maxMin(n, origem, grafo, vertices);

    return 0;
}
