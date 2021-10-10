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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* a[100010];
        int i = 1;
        while(head){
            a[i++] = head;
            head = head->next; 
        }
        int f = k;
        int s = i-k;
        if(f == s)return a[1];
        a[f]->val = a[f]->val + a[s]->val;
        a[s]->val = a[f]->val - a[s]->val;
        a[f]->val = a[f]->val - a[s]->val;
        return a[1];
    }
};