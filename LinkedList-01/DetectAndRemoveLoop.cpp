#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void detectAndRemoveLoop(Node* head) {
    if (!head || !head->next) return;

    Node *slow = head, *fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {  
            slow = head;
            if (slow == fast) {  // If loop is at head node
                while (fast->next != slow)
                    fast = fast->next;
            } 
            else { // Move slow and fast one node at a time
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            fast->next = nullptr; 
            return;
        }
    }
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(50);
    head->next = new Node(20);
    head->next->next = new Node(15);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(10);

    head->next->next->next->next->next = head->next->next;

    detectAndRemoveLoop(head);

    cout << "Linked List after removing loop:\n";
    printList(head);

    return 0;
}


/*
Approach : 
1. Use Floyd's Cycle Detection Algorithm (Tortoise and Hare).
2. Initialize two pointers, slow and fast.
3. Move slow by one step and fast by two steps.
4. If they meet, a loop exists.
5. To find the start of the loop, move slow to head and keep fast at meeting point.
6. Move both one step at a time until they meet again.
7. The meeting point is the start of the loop.
8. To remove the loop, find the last node in the loop and set its next to NULL.
*/