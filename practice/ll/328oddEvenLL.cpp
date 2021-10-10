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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* headEven = head->next;
        ListNode* curO = head;
        ListNode* curE = headEven;
        bool odd = true;
        while(  curE->next && curO->next  ){
            if( odd  ){
                curO->next = curE->next;
                odd = false;
                curO = curO->next;
            }
            else{
                curE->next = curO->next;
                odd = true;
                curE = curE->next;
            }
        }
        curO->next = headEven;
        curE->next = NULL;
        return head;
    }
};