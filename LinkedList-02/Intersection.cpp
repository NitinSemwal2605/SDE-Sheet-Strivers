#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode*a = headA;
    ListNode*b = headB;

    while(a!=b){
        if(a == NULL) a=headB;
        else a = a-> next;

        if(b== NULL) b=headA;
        else b= b -> next;
    }
    return a;
}

int main() {
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next;

    ListNode* result = getIntersectionNode(headA, headB);
    cout << result->val << endl;
    return 0;
}

/*
Approach :
1. Initialize two pointers, a and b, to the heads of the two linked lists.
2. Traverse both lists simultaneously. If a reaches the end of list A, redirect it to the head of list B. Similarly, if b reaches the end of list B, redirect it to the head of list A.
3. Continue this process until a and b meet at the intersection point or both reach the end (NULL).
4. If they meet, return the intersection node; otherwise, return NULL.
Time Complexity: O(n)
Space Complexity: O(1)
*/