#include <bits/stdc++.h>
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

void insertAtHead(Node*& tail, int value) {
    Node* newNode = new Node(value);
    if (tail == nullptr) {
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
}

void insertAtTail(Node*& tail, int value) {
    Node* newNode = new Node(value);
    if (tail == nullptr) {
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtPosition(Node*& tail, int position, int value) {
    if (tail == nullptr || position == 0) {
        insertAtHead(tail, value);
        return;
    }

    Node* current = tail->next;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
        if (current == tail->next) {
            cout << "Position out of bounds." << endl;
            return;
        }
    }

    Node* newNode = new Node(value);
    newNode->next = current->next;
    current->next = newNode;

    if (current == tail) {
        tail = newNode;
    }
}

void deleteAtHead(Node*& tail) {
    if (tail == nullptr) return;

    Node* head = tail->next;
    if (tail == head) {
        delete head;
        tail = nullptr;
    } else {
        tail->next = head->next;
        delete head;
    }
}

void deleteAtTail(Node*& tail) {
    if (tail == nullptr) return;

    Node* current = tail->next;

    if (current == tail) {
        delete tail;
        tail = nullptr;
        return;
    }

    while (current->next != tail) {
        current = current->next;
    }

    current->next = tail->next;
    delete tail;
    tail = current;
}

void deleteAtPosition(Node*& tail, int position) {
    if (tail == nullptr) return;

    if (position == 0) {
        deleteAtHead(tail);
        return;
    }

    Node* current = tail->next;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
        if (current == tail) {
            cout << "Position out of bounds." << endl;
            return;
        }
    }

    Node* temp = current->next;
    if (temp == tail) {
        deleteAtTail(tail);
    } else {
        current->next = temp->next;
        delete temp;
    }
}

void printList(Node* tail) {
    if (tail == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = tail->next;
    do {
        cout << current->data << " -> ";
        current = current->next;
    } while (current != tail->next);
    cout << "(head again)" << endl;
}

// Main function to test everything
int main() {
    Node* tail = nullptr;

    insertAtHead(tail, 10);
    insertAtTail(tail, 20);
    insertAtPosition(tail, 1, 15); // Insert between 10 and 20

    cout << "List after insertions: ";
    printList(tail);

    deleteAtHead(tail);
    cout << "After deleting head: ";
    printList(tail);

    deleteAtTail(tail);
    cout << "After deleting tail: ";
    printList(tail);

    deleteAtPosition(tail, 0);
    cout << "After deleting position 0: ";
    printList(tail);

    return 0;
}
