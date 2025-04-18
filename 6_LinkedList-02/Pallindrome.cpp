#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
    private:
      ListNode* getMid(ListNode* head ) {
          ListNode* slow = head;
          ListNode* fast = head -> next;
          
          while(fast != NULL && fast-> next != NULL) {
              fast = fast -> next -> next;
              slow = slow -> next;
          }
          
          return slow;
      }
      ListNode* reverse(ListNode* head) {
          
          ListNode* curr = head;
          ListNode* prev = NULL;
          ListNode* next = NULL;
          
          while(curr != NULL) {
              next = curr -> next;
              curr -> next = prev;
              prev = curr;
              curr = next;
          }
          return prev;
      }
    public:
      bool isPalindrome(ListNode *head)
      {
          if(head -> next == NULL) {
              return true;
          }
          
          //step 1 -> find Middle
          ListNode* middle = getMid(head);
          
          //step2 -> reverse List after Middle
          ListNode* temp = middle -> next;
          middle -> next = reverse(temp);
          
          //step3 - Compare both halves
          ListNode* head1 = head;
          ListNode* head2 = middle -> next;
          
          while(head2 != NULL) {
              if(head2->val != head1->val) {
                  return 0;
              }
              head1 = head1 -> next;
              head2 = head2 -> next;
          }
      
          //step4 - repeat step 2
          temp = middle -> next;
          middle -> next = reverse(temp);
          
          return true;
      }
  };

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    
    Solution s;
    cout << s.isPalindrome(head) << endl;
    return 0;
}