#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Matriz {
private:
    Node* head;  // Ponteiro para o primeiro nó da lista
    Node* ultimo;  // Ponteiro para o último nó da lista

public:
    // Construtor
    Matriz() : head(nullptr), ultimo(nullptr) {}

    // Destrutor para liberar memória
    ~Matriz() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Inserir múltiplos elementos no topo da matriz
    void insereTopo(std::initializer_list<int> values) {
        for (int value : values) {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
            if (ultimo == nullptr) {
                ultimo = head;
            }
        }
    }

    // Inserir múltiplos elementos no final da matriz
    void insereFim(std::initializer_list<int> values) {
        for (int value : values) {
            Node* newNode = new Node(value);
            if (ultimo == nullptr) {
                head = ultimo = newNode;
            } else {
                ultimo->next = newNode;
                ultimo = newNode;
            }
        }
    }

    // Remover múltiplos elementos do topo da matriz
    void removeTopo(int count) {
        while (count-- > 0 && head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) {
                ultimo = nullptr;
            }
        }
    }

    // Remover múltiplos elementos do final da matriz
    void removeFim(int count) {
        while (count-- > 0 && head != nullptr) {
            if (head->next == nullptr) {
                delete head;
                head = ultimo = nullptr;
            } else {
                Node* current = head;
                while (current->next != ultimo) {
                    current = current->next;
                }
                delete ultimo;
                ultimo = current;
                ultimo->next = nullptr;
            }
        }
    }

    // Método para verificar se a matriz contém um determinado valor
    bool contem(int value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Imprimir os elementos da matriz
    void printMatriz() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Matriz matriz;

    matriz.insereTopo({10, 20, 30});
    matriz.insereFim({40, 50, 60});

    std::cout << "Matriz: ";
    matriz.printMatriz();

    matriz.removeTopo(2);
    std::cout << "Matriz após remover K elementos do topo: ";
    matriz.printMatriz();

    matriz.removeFim(2);
    std::cout << "Matriz após remover K elementos do fim: ";
    matriz.printMatriz();

    // Verificar se a matriz contém um valor
    int valorProcurado = 40;
    if (matriz.contem(valorProcurado)) {
        std::cout << "A matriz contém o valor " << valorProcurado << "." << std::endl;
    } else {
        std::cout << "A matriz não contém o valor " << valorProcurado << "." << std::endl;
    }

    return 0;
}
