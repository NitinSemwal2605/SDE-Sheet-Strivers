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

/*
Approach :
1. We will use recursion to merge the two lists.
2. If one of the lists is empty, we return the other list.
3. If the first node of list1 is smaller than or equal to the first node of list2, we set the next of list1 to the result of merging the next node of list1 with list2.
4. Otherwise, we set the next of list2 to the result of merging list1 with the next node of list2.
5. Finally, we return the merged list.
6. The time complexity of this approach is O(n + m), where n and m are the lengths of the two lists.
*/