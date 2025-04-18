#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // 1. Find the length and the last node
    ListNode* curr = head;
    int length = 1;
    while (curr->next) {
        curr = curr->next;
        length++;
    }

    // 2. Make it circular
    curr->next = head;

    // 3. Find the new tail: length - k % length - 1 steps from head
    k = k % length;
    int stepsToNewTail = length - k;
    ListNode* newTail = head;
    for (int i = 1; i < stepsToNewTail; i++) {
        newTail = newTail->next;
    }

    // 4. Break the circle and set the new head
    ListNode* newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
}

void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2; // Rotate by 2 positions

    cout << "Original list: ";
    printList(head);

    ListNode* rotatedHead = rotateRight(head, k);

    cout << "Rotated list: ";
    printList(rotatedHead);

    return 0;
}