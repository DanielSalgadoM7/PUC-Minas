#include <iostream>
#include <vector>
#include <bitset>
#include <cmath> // Para usar a função pow

using namespace std;

// função para calcular o fatorial, pra usar naquele calculo de máximo de arestas
int fatorial(int num) {
    int resultado = 1;
    for (int i = 1; i <= num; i++) {
        resultado *= i;
    }
    return resultado;
}

// função para calcular o número total de subgrafos possíveis com uma quantidade X de vértice
int calculaSubgrafo(int vertice) {
    int binomial = 0;
    int resultado = 0;
    for (int i = 1; i <= vertice; i++) {
        binomial = (fatorial(vertice) / (fatorial(i) * fatorial(vertice - i)));
        resultado += pow(2, (i * (i - 1) / 2)) * binomial;
    }

    return resultado;
}

// função para imprimir o subgrafo
void imprimeSubgrafo(const vector<int>& vertices, const vector<pair<int, int>>& arestas) {
    cout << "Subgrafo com vértices: ";
    for (int v : vertices) {
        cout << v << " ";
    }
    cout << "\nArestas: ";
    for (const auto& aresta : arestas) {
        cout << "(" << aresta.first << ", " << aresta.second << ") ";
    }
    cout << "\n";
}

// função para gerar todas as combinações de arestas para um subconjunto de vértices
void geraCombinacoesDeArestas(const vector<int>& vertices, int& totalSubgrafos) {
    int numVertices = vertices.size();
    int totalArestas = (numVertices * (numVertices - 1)) / 2;

    // Gerar todas as combinações possíveis de arestas
    for (int mascara = 0; mascara < (1 << totalArestas); ++mascara) {
        vector<pair<int, int>> arestas;
        int indiceAresta = 0;

        // Combinações de pares de vértices
        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = i + 1; j < numVertices; ++j) {
                if (mascara & (1 << indiceAresta)) {
                    arestas.emplace_back(vertices[i], vertices[j]);
                }
                indiceAresta++;
            }
        }

        // Imprimir o subgrafo atual
        imprimeSubgrafo(vertices, arestas);
        ++totalSubgrafos;
    }
}

// função para gerar todos os subgrafos de um grafo completo
void geraSubgrafos(int n) {
    int totalSubgrafos = 0;

    // Iterar sobre todos os subconjuntos de vértices
    for (int mascara = 1; mascara < (1 << n); ++mascara) {  // Começar de 1 para evitar o subconjunto vazio
        vector<int> vertices;

        // Determinar os vértices no subconjunto atual
        for (int i = 0; i < n; ++i) {
            if (mascara & (1 << i)) {
                vertices.push_back(i + 1); // Considerando vértices 1-indexados
            }
        }

        // Gerar todas as combinações de arestas para os vértices atuais
        geraCombinacoesDeArestas(vertices, totalSubgrafos);
    }

    cout << "Número total de subgrafos gerados: " << totalSubgrafos << endl;

}

int main() {
    int vertice;

    cout << "Informe o número de vértices no grafo completo: ";
    cin >> vertice;

    while (vertice <= 0) {
        cout << "Número de vértices deve ser positivo." << endl;
        cin >> vertice;
    }

    geraSubgrafos(vertice);

    return 0;
}
