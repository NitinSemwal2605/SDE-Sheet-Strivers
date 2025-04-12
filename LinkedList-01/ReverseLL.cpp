#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* reverseLL(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
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
    head = reverseLL(head);
    printLL(head);

    return 0;
}


/*
Approach :
1. Initialize three pointers: prev, curr, and next.
2. Set prev to NULL and curr to the head of the linked list.
3. Iterate through the list until curr is NULL:
   a. Store the next node (curr->next) in next.
   b. Reverse the link by setting curr->next to prev.
   c. Move prev and curr one step forward.
4. When curr becomes NULL, prev will be the new head of the reversed list.
5. Return prev as the new head of the reversed linked list.
6. Print the reversed linked list.
*/