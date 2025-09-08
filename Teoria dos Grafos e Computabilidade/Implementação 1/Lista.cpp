#include <iostream>
#include <initializer_list>

struct Node {
    int data;        
    Node* next;      

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    // Construtor
    LinkedList() : head(nullptr) {}

    ~LinkedList() { // Destruidor
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Inserir múltiplos elementos na cabeça da lista
    void inseretopo(std::initializer_list<int> values) {
        for (int value : values) {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        }
    }

    // Inserir múltiplos elementos no final da lista
    void inserefim(std::initializer_list<int> values) {
        for (int value : values) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* current = head;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newNode;
            }
        }
    }

    // Remover múltiplos elementos pela cabeça da lista
    void removerTopo(int count) {
        for (int i = 0; i < count && head != nullptr; ++i) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Remover múltiplos elementos do final da lista
    void removerFim(int count) {
        while (count-- > 0 && head != nullptr) {
            if (head->next == nullptr) {
                delete head;
                head = nullptr;
            } else {
                Node* current = head;
                while (current->next->next != nullptr) {
                    current = current->next;
                }
                delete current->next;
                current->next = nullptr;
            }
        }
    }

    // Método para verificar se a lista contém um determinado valor
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

    void printLista() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;

    list.inseretopo({10, 20, 30});
    list.inserefim({40, 50, 60});
    

    std::cout << "Lista encadeada: ";
    list.printLista();

    list.removerTopo(2);
    std::cout << "Lista após remover 2 elementos do topo: ";
    list.printLista();

    list.removerFim(2);
    std::cout << "Lista após remover 2 elementos do fim: ";
    list.printLista();

    // Verificar se a lista contém um valor
    int valorProcurado = 40;
    if (list.contem(valorProcurado)) {
        std::cout << "A lista contém o valor " << valorProcurado << "." << std::endl;
    } else {
        std::cout << "A lista não contém o valor " << valorProcurado << "." << std::endl;
    }

    return 0;
}
