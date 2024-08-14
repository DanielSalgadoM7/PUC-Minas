#include <iostream>
#include <initializer_list>

// Estrutura do nó da fila
struct Node {
    int data;        // Dados armazenados no nó
    Node* next;      // Ponteiro para o próximo nó

    // Construtor para inicializar o nó com um valor
    Node(int value) : data(value), next(nullptr) {}
};

// Classe para a fila
class Queue {
private:
    Node* front;    // Ponteiro para o início da fila
    Node* rear;     // Ponteiro para o final da fila

public:
    // Construtor
    Queue() : front(nullptr), rear(nullptr) {}

    // Destruidor
    ~Queue() {
        // Libera toda a memória alocada para a fila
        while (!isEmpty()) {
            remover();
        }
    }

    // Função para adicionar um elemento na fila
    void insere(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Função para adicionar múltiplos elementos na fila
    void insereN(std::initializer_list<int> values) {
        for (int value : values) {
            insere(value);
        }
    }

    // Função para remover o elemento do início da fila
    void remover() {
        if (isEmpty()) {
            std::cerr << "Fila vazia. Não é possível remover elementos." << std::endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr; // Se a fila ficar vazia, rear também deve ser nullptr
        }
        delete temp;
    }

    // Função para remover múltiplos elementos do início da fila
    void removerK(int count) {
        for (int i = 0; i < count; ++i) {
            if (!isEmpty()) {
                remover();
            } else {
                std::cerr << "Fila vazia após remover " << i << " elementos." << std::endl;
                break;
            }
        }
    }

    // Função para verificar se a fila está vazia
    bool isEmpty() const {
        return front == nullptr;
    }

    // Função para verificar se um elemento está na fila
    bool contem(int value) const {
        Node* current = front;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Função para imprimir todos os elementos da fila
    void printFila() const {
        Node* current = front;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue fila;

    // Adicionando múltiplos elementos à fila
    fila.insereN({10, 20, 30, 40});
    fila.insere(50);

    std::cout << "Fila atual: ";
    fila.printFila();

    // Remover múltiplos elementos da fila
    fila.removerK(2);
    fila.remover();
    std::cout << "Fila após removerK e remover: ";
    fila.printFila();

    return 0;
}
