// Resolve Loop in Linked list using set

#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* resolveLoop(ListNode* head) {
    unordered_set<ListNode*> visited;
    ListNode* current = head;

    while (current != NULL) {
        if (visited.find(current) != visited.end()) {
            // Loop detected, remove the loop
            ListNode* temp = current;
            while (temp->next != current) {
                temp = temp->next;
            }
            temp->next = NULL; // Break the loop
            return head;
        }
        visited.insert(current);
        current = current->next;
    }
    return head; // No loop detected
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next; // Creating a loop

    head = resolveLoop(head);

    // Print the list after resolving the loop
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}