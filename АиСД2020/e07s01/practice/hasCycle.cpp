#include <iostream>

// Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL ) return false;
        ListNode* cur = head->next;
        while( cur->next != NULL ){
            if(cur == head){
                return true;
            }
            else{
                ListNode* temp = cur;
                cur = cur->next;
                temp->next = head;
            }
        }
        return false;
    }
};