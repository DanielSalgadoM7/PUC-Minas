w#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

// Função para imprimir um subgrafo
void printSubgraph(const vector<int>& vertices, const vector<pair<int, int>>& edges) {
    cout << "Subgrafo com vertices: ";
    for (int v : vertices) {
        cout << v << " ";
    }
    cout << "\nArestas: ";
    for (const auto& edge : edges) {
        cout << "(" << edge.first << ", " << edge.second << ") ";
    }
    cout << "\n";
}

// Função para gerar todas as combinações de arestas para um subconjunto de vértices
void generateEdgeCombinations(const vector<int>& vertices, int& totalSubgraphs) {
    int numVertices = vertices.size();
    int totalEdges = (numVertices * (numVertices - 1)) / 2;

    // Gerar todas as combinações possíveis de arestas
    for (int mask = 0; mask < (1 << totalEdges); ++mask) {
        vector<pair<int, int>> edges;
        int edgeIndex = 0;

        // Combinações de pares de vértices
        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = i + 1; j < numVertices; ++j) {
                if (mask & (1 << edgeIndex)) {
                    edges.emplace_back(vertices[i], vertices[j]);
                }
                edgeIndex++;
            }
        }

        // Imprimir o subgrafo atual
        printSubgraph(vertices, edges);
        ++totalSubgraphs;
    }
}

// Função para gerar todos os subgrafos de um grafo completo
void generateSubgraphs(int n) {
    int totalSubgraphs = 0;

    // Iterar sobre todos os subconjuntos de vértices
    for (int mask = 1; mask < (1 << n); ++mask) {  // Começar de 1 para evitar o subconjunto vazio
        vector<int> vertices;

        // Determinar os vértices no subconjunto atual
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                vertices.push_back(i + 1); // Considerando vértices 1-indexados
            }
        }

        // Gerar todas as combinações de arestas para os vértices atuais
        generateEdgeCombinations(vertices, totalSubgraphs);
    }

    cout << "Numero total de subgrafos: " << totalSubgraphs << endl;
}

int main() {
    int n;

    cout << "Informe o numero de vertices no grafo completo: ";
    cin >> n;

    if (n <= 0) {
        cout << "Numero de vertices deve ser positivo." << endl;
        return 1;
    }

    generateSubgraphs(n);

    return 0;
}
---------------------------------------------------------------
#include <iostream>
#include <cmath> // Para usar a função pow

using namespace std;

int fatorial(int num){
    int resultado = 1;
    for(int i=1;i<=num;i++){
        resultado *= i;
    }
    return resultado;
}

int calculaSubgrafo(int vertice){
    int binomial = 0;
    int resultado = 0;
    for(int i=1;i<=vertice;i++){
        binomial = (fatorial(vertice)/(fatorial(i)*fatorial(vertice-i)));
        resultado += pow(2, (i * (i - 1) / 2)) * binomial;
    }

    return resultado;
}

/*void mostraSubgrafo(int vertice, int aresta){
    for(int i=1;i<=vertice;i++){
        int arestaMax = (i*(i-1))/2;
        for(int j=0; j<=arestaMax;j++){
            
        }
    }
}*/

int main() {
    int vertice = 0;
    cin >> vertice;
    
    while(vertice <= 0){
        cout << "Numero de vertices deve ser positivo." << endl;
        cin >> vertice;
    }
   
    int arestaMax = (vertice*(vertice-1))/2;
    cout << "Quantidade de aresta máxima: " << arestaMax << endl;

    int totalSubgrafo = calculaSubgrafo(vertice);

    cout << "Quantidade de subgrafos: " << totalSubgrafo << endl;
    
    return 0;
}

