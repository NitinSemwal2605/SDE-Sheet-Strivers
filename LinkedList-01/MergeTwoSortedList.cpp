#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1  == NULL){
        return list2;
    }
    
    if(list2 == NULL){
        return list1;
    }
    
    if(list1 -> val <= list2 -> val ){
        list1 -> next = mergeTwoLists(list1 -> next, list2);
        return list1;
    }
    else{
        list2 -> next = mergeTwoLists(list1, list2 -> next);
        return list2;            
    }
}

int main() {
    ListNode* list1 = new ListNode(1);
    list1 -> next = new ListNode(2);
    list1 -> next -> next = new ListNode(4);
    
    ListNode* list2 = new ListNode(1);
    list2 -> next = new ListNode(3);
    list2 -> next -> next = new ListNode(4);
    
    ListNode* mergedList = mergeTwoLists(list1, list2);
    
    while(mergedList != NULL){
        cout << mergedList -> val << " ";
        mergedList = mergedList -> next;
    }
    return 0;
}