#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr; // Initialize prev to nullptr
    }
};


void insertAtHead(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head != nullptr) {
        head->prev = newNode; // Set the previous pointer of the old head
    }
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node*& tail, int value) {
    Node* newNode = new Node(value);
    if (tail == nullptr) {
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail; // Set the previous pointer of the new node
        tail = newNode;
    }
}

void insertAtPosition(Node*& head, Node*& tail, int position, int value) {
    if (position == 0) {
        insertAtHead(head, value);
        if (tail == nullptr) {
            tail = head; // If the list was empty, set tail to head
        }
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
    newNode->prev = current;
    
    if (current->next != nullptr) {
        current->next->prev = newNode; // Set the previous pointer of the next node
    } else {
        tail = newNode; // If inserting at the end, update tail
    }

    current->next = newNode;
}


void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " <-> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}


void printReverse(Node* tail) {
    Node* current = tail;
    while (current != nullptr) {
        cout << current->data << " <-> ";
        current = current->prev;
    }
    cout << "nullptr" << endl;
}

// delete at head, tail, position

void deleteAtHead(Node*& head) {
    if (head == nullptr) return; // List is empty
    Node* toDelete = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr; // Update the new head's prev pointer
    }
    delete toDelete;
}

void deleteAtTail(Node*& tail) {
    if (tail == nullptr) return; // List is empty
    Node* toDelete = tail;
    tail = tail->prev;
    if (tail != nullptr) {
        tail->next = nullptr; // Update the new tail's next pointer
    }
    delete toDelete;
}

void deleteAtPosition(Node*& head, Node*& tail, int position) {
    if (head == nullptr) return; // List is empty

    if (position == 0) {
        deleteAtHead(head);
        if (head == nullptr) {
            tail = nullptr; // If the list is now empty, update tail
        }
        return;
    }

    Node* current = head;
    for (int i = 0; i < position && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Position out of bounds." << endl;
        return;
    }

    if (current->prev != nullptr) {
        current->prev->next = current->next; // Update the next pointer of the previous node
    }
    
    if (current->next != nullptr) {
        current->next->prev = current->prev; // Update the prev pointer of the next node
    } else {
        tail = current->prev; // If deleting the last node, update tail
    }

    delete current;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    insertAtHead(head, 10);
    insertAtTail(tail, 20);
    insertAtPosition(head, tail, 1, 15);
    
    cout << "List after insertions: ";
    printList(head);
    
    cout << "List in reverse: ";
    printReverse(tail);

    deleteAtHead(head);
    cout << "List after deleting head: ";
    printList(head);

    deleteAtTail(tail);
    cout << "List after deleting tail: ";
    printList(head);

    deleteAtPosition(head, tail, 0);
    cout << "List after deleting position 0: ";
    printList(head);

    return 0;
}