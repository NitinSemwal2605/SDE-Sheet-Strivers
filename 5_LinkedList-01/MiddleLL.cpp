#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* middleLL(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void printLL(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    printLL(head);
    Node* middle = middleLL(head);
    cout << middle->data << endl;

    return 0;
}


/*
Approach : 
1. Initialize two pointers, slow and fast, both pointing to the head of the linked list.
2. Move the slow pointer one step at a time and the fast pointer two steps at a time.
3. When the fast pointer reaches the end of the list, the slow pointer will be at the middle.
4. If the list has an even number of nodes, the slow pointer will point to the second middle node.
5. Return the slow pointer as the middle node.
*/