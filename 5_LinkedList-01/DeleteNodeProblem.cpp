#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
};

void deleteNode(ListNode* node) { // 4519 , node-5
    if (node == nullptr || node->next == nullptr) {
        return;
    }

    node->val = node->next->val; // 4519 -> 4119
    ListNode* temp = node->next; // (store 1)
    node->next = node->next->next; // 419
    delete temp; // delete 1 that was stored
}

void printLL(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    ListNode* l1 = new ListNode();
    ListNode* l2 = new ListNode();
    ListNode* l3 = new ListNode();
    ListNode* l4 = new ListNode();
    ListNode* l5 = new ListNode();
    ListNode* l6 = new ListNode();

    l1->val = 4;
    l1->next = l2;

    l2->val = 5;
    l2->next = l3;

    l3->val = 1;
    l3->next = l4;

    l4->val = 9;
    l4->next = l5;

    l5->val = 0;
    l5->next = l6;

    l6->val = 3;
    l6->next = NULL;

    printLL(l1);
    deleteNode(l2);
    printLL(l1);

    return 0;
}