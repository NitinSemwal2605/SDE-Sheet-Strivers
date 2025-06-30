#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = nullptr;
        }
};

void insertAtHead(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

void insertAtPosition(Node*& head, int position, int value) {
    if (position == 0) {
        insertAtHead(head, value);
        return;
    }

    Node* newNode = new Node(value);
    Node* current = head;

    for (int i = 0; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Position out of bounds." << endl;
        delete newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}


void deleteAtHead(Node*& head) {
    if (head == nullptr) return; // List is empty
    Node* toDelete = head;
    head = head->next;
    delete toDelete;
}

void deleteAtTail(Node*& head) {
    if (head == nullptr) return; // List is empty
    if (head->next == nullptr) { // Only one node
        delete head;
        head = nullptr;
        return;
    }
    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next; // Delete the last node
    current->next = nullptr; // Set the second last node's next to nullptr
}

void deleteAtPosition(Node*& head, int position) {
    if (head == nullptr) return; // List is empty

    if (position == 0) {
        deleteAtHead(head);
        return;
    }

    Node* current = head;
    for (int i = 0; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "Position out of bounds." << endl;
        return;
    }

    Node* toDelete = current->next;
    current->next = toDelete->next; // Bypass the node to delete
    delete toDelete;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr;

    insertAtHead(head, 10);
    insertAtTail(head, 20);
    insertAtPosition(head, 1, 15);

    cout << "List after insertions: ";
    printList(head);

    deleteAtHead(head);
    cout << "List after deleting head: ";
    printList(head);

    deleteAtTail(head);
    cout << "List after deleting tail: ";
    printList(head);

    deleteAtPosition(head, 0);
    cout << "List after deleting at position 0: ";
    printList(head);

    return 0;
}