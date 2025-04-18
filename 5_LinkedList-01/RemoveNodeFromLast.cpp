#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;
    ListNode(int val) {
        data = val;
        next = nullptr;
    }
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy -> next = head;

    ListNode* slow = dummy;
    ListNode* fast = dummy;

    for(int i=0;i<n;i++){
        if (fast == nullptr) return nullptr;
        fast = fast-> next;
    }

    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;
    return dummy->next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(50);
    head->next = new ListNode(20);
    head->next->next = new ListNode(15);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(10);

    head = removeNthFromEnd(head, 2);

    cout << "Linked List after removing 2nd node from end:\n";
    printList(head);
    return 0;
}


/*
Approach :
1. Create a dummy node and point its next to the head of the linked list.
2. Initialize two pointers, slow and fast, both pointing to the dummy node.
3. Move the fast pointer n steps ahead.
4. Move both slow and fast pointers until the fast pointer reaches the end of the list.
5. The slow pointer will be pointing to the node before the one we want to remove.
6. Update the next pointer of the slow node to skip the node to be removed.
7. Return the next pointer of the dummy node as the new head of the linked list.
8. Print the modified linked list.
*/