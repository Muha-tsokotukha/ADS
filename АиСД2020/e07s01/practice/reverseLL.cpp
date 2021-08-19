#include <iostream>
using namespace std;

    //  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        head = rev(head );
        return head;
    }
    
    ListNode* rev( ListNode* cur ){
        if(cur == NULL) return NULL;
        if(  cur->next == NULL ){
            //head = cur;
            return cur;
        }
        ListNode* h = rev( cur->next  );
        ListNode* t = cur->next; // cur->next->next = cur 
        t->next = cur;
        cur->next= NULL;
        return h;
    }
};