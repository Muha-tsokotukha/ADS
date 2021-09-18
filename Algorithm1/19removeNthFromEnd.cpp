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
class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; i++) fast = fast->next;
        if (!fast) return head->next;
        while (fast->next) fast = fast->next, slow = slow->next;
        slow->next = slow->next->next;
        return head;
    }
};
class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        int sz = 0;
        while(cur){
            sz++; 
            cur = cur->next;
        }
        int ind  = 0;
        if( ind == sz - n  ){
            head = head->next;
        }else{
            ListNode* prev = head;
            cur = head->next;
            while(ind != sz - n -1 && cur->next ){
                ind++;
                cur = cur->next;
                prev = prev->next;
            }
            prev->next = cur->next;
        }
        
        
        return head;
    }
};



class Solution3 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* arr[31];
        ListNode* cur = head;
        int i = 1;
        while(cur){
            arr[i] = cur;
            cur = cur->next;
            i++;
        }
        if( i-1 == n  ){
            return head->next;
        }
        else{
            arr[i-n-1]->next = arr[i-n]->next;
        }
        
        
        
        return arr[1];
    }
};