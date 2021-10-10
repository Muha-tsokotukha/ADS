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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* fst ;ListNode* scnd;
        ListNode* cur= list1;
        int i = 0;a--;
        while(i < a){
            i++; cur = cur->next;
        }
        fst = cur;
        while(i <= b){
            i++; cur = cur->next;
        }
        scnd = cur;
        fst->next = list2;
        while(list2->next)list2 = list2->next;
        list2->next = scnd;
        return list1;
    }
};