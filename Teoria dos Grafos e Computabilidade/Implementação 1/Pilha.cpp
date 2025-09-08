#include <iostream>
#include <initializer_list>

// Estrutura do nó da pilha
struct Node {
    int data;        // Dados armazenados no nó
    Node* next;      // Ponteiro para o próximo nó

    // Construtor para inicializar o nó com um valor
    Node(int value) : data(value), next(nullptr) {}
};

// Classe para a pilha
class Stack {
private:
    Node* top;      // Ponteiro para o topo da pilha

public:
    // Construtor
    Stack() : top(nullptr) {}

    // Destruidor
    ~Stack() {
        // Libera toda a memória alocada para a pilha
        while (!isEmpty()) {
            remover();
        }
    }

    // Função para adicionar um elemento na pilha
    void insere(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Função para adicionar n elementos na pilha
    void insereN(std::initializer_list<int> values) {
        for (int value : values) {
            insere(value);
        }
    }

    // Função para remover o elemento do topo da pilha
    void remover() {
        if (isEmpty()) {
            std::cerr << "Pilha vazia. Não é possível remover elementos." << std::endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Função para remover k elementos do topo da pilha
    void removerK(int count) {
        for (int i = 0; i < count; ++i) {
            if (!isEmpty()) {
                remover();
            } else {
                // checagem se a pilha não ficou vazia
                std::cerr << "Pilha vazia após remover " << i << " elementos." << std::endl;
                break;
            }
        }
    }

    // Função para obter o elemento do topo da pilha
    int topo() const {
        if (isEmpty()) {
            std::cerr << "Pilha vazia. Não é possível acessar o elemento do topo." << std::endl;
            return -1; // Valor de erro
        }
        return top->data;
    }

    // Função para verificar se a pilha está vazia
    bool isEmpty() const {
        return top == nullptr;
    }

    // Função para imprimir todos os elementos da pilha
    void printPilha() const {
        Node* current = top;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Função para verificar se a pilha contém um elemento específico
    bool contem(int value) const {
        Node* current = top;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

int main() {
    Stack stack;

    // Adicionando múltiplos elementos à pilha
    stack.insereN({10, 20, 30, 40});
    stack.insere(50);

    std::cout << "Pilha atual: ";
    stack.printPilha();

    std::cout << "Topo da pilha: " << stack.topo() << std::endl;

    // Removendo múltiplos elementos da pilha
    stack.removerK(2);
    stack.remover();
    std::cout << "Pilha após removerK e remover: ";
    stack.printPilha();

    std::cout << "Topo da pilha após removerK e remover: " << stack.topo() << std::endl;

    // Verificando se a pilha contém determinados elementos
    int elemento = 20;
    if (stack.contem(elemento)) {
        std::cout << "A pilha contém o elemento " << elemento << "." << std::endl;
    } else {
        std::cout << "A pilha não contém o elemento " << elemento << "." << std::endl;
    }

    elemento = 50;
    if (stack.contem(elemento)) {
        std::cout << "A pilha contém o elemento " << elemento << "." << std::endl;
    } else {
        std::cout << "A pilha não contém o elemento " << elemento << "." << std::endl;
    }

    return 0;
}
