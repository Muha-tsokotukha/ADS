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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* cur = head;
        map<int,int> m;
 
        while(cur){
            if(m[cur->val])m[cur->val]++;
            else m[cur->val] = 1;
            cur = cur->next;
        }
        while( m[head->val] >1   ){
            head = head->next;
            if(!head)return NULL;
        }
        ListNode* prev = head;
        cur = head->next;
        while( cur  ){
            if( m[cur->val] >1  ){
                prev->next = cur->next;
                cur = cur->next;
            }
            else{
                cur = cur->next;
                prev = prev->next;
            }
        }
        return head;
    }
};