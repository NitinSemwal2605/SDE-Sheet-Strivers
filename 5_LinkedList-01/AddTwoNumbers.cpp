#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummy = new Node();  
    Node* temp = dummy;
    int carry = 0;
    while(l1 != NULL || l2 != NULL || carry) {
        int sum = 0;
        if(l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }
        if(l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum / 10;
        Node* newNode = new Node();
        newNode->data = sum % 10;
        temp->next = newNode;
        temp = temp->next;
    }
    return dummy->next;
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
    Node* l1 = new Node();
    Node* l2 = new Node();
    Node* l3 = new Node();
    Node* l4 = new Node();
    Node* l5 = new Node();
    Node* l6 = new Node();

    l1->data = 2;
    l1->next = l2;

    l2->data = 4;
    l2->next = l3;

    l3->data = 3;
    l3->next = NULL;

    l4->data = 5;
    l4->next = l5;

    l5->data = 6;
    l5->next = l6;

    l6->data = 4;
    l6->next = NULL;

    printLL(l1);
    printLL(l4);
    Node* result = addTwoNumbers(l1, l4);
    printLL(result);

    return 0;
}


/*
Approach :
1. Create a dummy node to simplify the process of adding nodes to the result list.
2. Initialize a pointer to the dummy node and a carry variable to 0.
3. Traverse both linked lists until both are null and there is no carry left.
4. For each iteration, calculate the sum of the current digits and the carry.
5. Create a new node with the value of sum % 10 and add it to the result list.
6. Update the carry to sum / 10.
7. Move to the next nodes in both linked lists.
8. Return the next node of the dummy node as the head of the result list.
*/
