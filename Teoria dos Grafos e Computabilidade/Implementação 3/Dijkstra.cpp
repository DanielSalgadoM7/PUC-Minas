#include <iostream>
#include <vector>
#include <climits> // Para usar INT_MAX como infinito
#include <algorithm> // Para usar reverse

using namespace std;

struct Aresta {
    int destino, peso;
};

struct Vertice {
    int distancia = INT_MAX; // Distância inicial é infinito
    int antecessor = -1;     // Antecessor inicial é indefinido
    bool visitado = false;   // Indica se o vértice já foi visitado
};

// Função que mostra o caminho e a distância de origem até destino
void mostrarCaminho(int destino, int origem, const vector<Vertice>& vertices) {
    if (vertices[destino].distancia == INT_MAX) {
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
        cout << " | Distância: " << vertices[destino].distancia << endl;
    }
}

void dijkstra(int n, int origem, vector<vector<Aresta>>& grafo, vector<Vertice>& vertices) {
    
    vertices[origem].distancia = 0; // A distância do vértice de origem para ele mesmo é 0

    for (int k = 0; k < n; k++) {
        // Encontra o vértice não visitado com a menor distância
        int y1 = -1;
        for (int i = 0; i < n; i++) {
            if (!vertices[i].visitado && (y1 == -1 || vertices[i].distancia < vertices[y1].distancia)) {
                y1 = i;
            }
        }

        if (y1 == -1) {
            break; // Se não houver mais vértices para visitar, termina
        }

        vertices[y1].visitado = true; // Marca o vértice como visitado

        // Atualiza as distâncias dos vizinhos de y1
        for (const Aresta& vizinho : grafo[y1]) {
            if (!vertices[vizinho.destino].visitado) {
                int novaDistancia = vertices[y1].distancia + vizinho.peso;
                if (novaDistancia < vertices[vizinho.destino].distancia) {
                    vertices[vizinho.destino].distancia = novaDistancia;
                    vertices[vizinho.destino].antecessor = y1; // Atualiza o antecessor
                }
            }
        }
    }


    // Mostra as distâncias e os caminhos para todos os vértices
    for (int i = 0; i < n; i++) {
        mostrarCaminho(i, origem,vertices);
    }
}

int main() {
    int n = 5; // Número de vértices

    vector<Vertice> vertices(n); // Vetor que armazena informações de cada vértice

    vector<vector<Aresta>> grafo(n); // o grafo é um vetor de inteiros(vertices), onde cada vertice possui um vetor de arestas

    // Adiciona as arestas ao grafo (Exemplo de grafo)
    grafo[0].push_back({1, 4});
    grafo[0].push_back({2, 3});
    grafo[1].push_back({2, 5});
    grafo[1].push_back({3, 2});
    grafo[2].push_back({4, 3});
    grafo[2].push_back({3, 1});
    grafo[3].push_back({4, 4});

    int origem = 0; // Vértice inicial (origem)

    dijkstra(n, origem, grafo, vertices);

    return 0;
}
