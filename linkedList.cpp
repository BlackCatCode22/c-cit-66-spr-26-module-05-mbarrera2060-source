#include <iostream>
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class linkedList {
    Node* head;
public:

    linkedList() : head(nullptr) {}
    ~linkedList() {

        Node* current = head;
        Node* nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void deleteByValue(int value) {
        Node* current = head;
        Node* prev = nullptr;
        if (current != nullptr && current->data == value) {
            head = current->next;
            delete current;
            return;
        }
        while (current != nullptr && current->data != value) {
            prev = current;
            current = current->next;
        }
        if (current == nullptr) return;
        prev->next = current->next;
        delete current;
    }
    void display() {
        Node* temp = head;
        if (temp == nullptr) {
            std::cout << "The list is empty." << std::endl;
            return;
        }
        std::cout << "List: ";
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};
int main() {
    linkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);

    std::cout << "After insertion: ";
    list.display();
    list.deleteByValue(2);

    std::cout << "After deleting 2: ";
    list.display();
    list.deleteByValue(100);

    std::cout << "After deleting 100: ";
    list.display();
    list.deleteByValue(1);

    std::cout << "After deleting 1: ";
    list.display();
    list.deleteByValue(3);

    std::cout << "After deleting 3: ";
    list.display();
    return 0;
}