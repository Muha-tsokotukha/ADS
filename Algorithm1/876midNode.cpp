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
    ListNode* middleNode(ListNode* head) {
        ListNode* cur = head;
        int sz =0;
        while(cur){
            sz++;
            cur = cur->next;
        }
        int ind = 0;
        while( ind != sz/2 ){
            head = head->next;
            ind++;
        }
        return head;
    }
};