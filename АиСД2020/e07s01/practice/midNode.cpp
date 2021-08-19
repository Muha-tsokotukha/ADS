#include <iostream>
using namespace std;

  // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// BIG BRAIN SOLUTION
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

class Solution2 {
public:
    ListNode* middleNode(ListNode* head) {
        int cnt = traverse(head)/2 + 1;
        int i = 1;
        while( i != cnt && head != NULL ){
            head = head->next;
            i++;
        }    
        return head;
    }
    
    
    int traverse(ListNode* cur){
        int sz = 0;
        while( cur != NULL ){
            sz++;
            cur = cur->next;
        }
        return sz;
    }
    
    
};