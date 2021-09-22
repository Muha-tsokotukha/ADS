/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) { // sorted LL
        if(head == NULL) return head;
        int lastVal = head->val;
        ListNode* lastNode = head;
        ListNode* cur = head->next;
        while( cur != NULL ){
            if(lastVal == cur->val){
                ListNode* neww = cur->next; 
                lastNode->next = cur->next;
                cur->next = NULL;
                cur = neww;
            }
            else{
                lastVal = cur->val;
                lastNode = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};