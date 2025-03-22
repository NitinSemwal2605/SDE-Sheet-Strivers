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