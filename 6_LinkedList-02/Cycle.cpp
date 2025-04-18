#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            ListNode* slow = head;
            ListNode* fast = head;
    
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
    
                if (slow == fast) {
                    slow = head;
    
                    while (slow != fast) {
                        slow = slow->next;
                        fast = fast->next;
                    }
                    return slow;
                }
            }
            return nullptr;
        }
    };
    

int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    Solution s;
    ListNode* result = s.detectCycle(head);
    cout << result->val << endl;
    return 0;
}


/*
Approach : 
1. Initialize two pointers, slow and fast. Both start at the head of the linked list.
2. Move the slow pointer one step at a time and the fast pointer two steps at a time.
3. If there is a cycle, the fast pointer will eventually meet the slow pointer.
4. Once they meet, move one pointer back to the head of the list and keep the other at the meeting point.
5. Move both pointers one step at a time until they meet again. The meeting point is the start of the cycle.
6. If the fast pointer reaches the end of the list (null), there is no cycle.
Time Complexity: O(n)
Space Complexity: O(1)
*/