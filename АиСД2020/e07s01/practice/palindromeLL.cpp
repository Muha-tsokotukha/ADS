#include <iostream>
#include <stack>
using namespace std;
   // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode* last = head->next;
        stack<int> s;
        while( last != NULL  ){
            s.push(last->val);
            last = last->next;
        }
        while(  !s.empty()  && head ){
            if( s.top() == head->val  ){
                s.pop();
                head = head->next;
            }else{return false;}
        }
        return true;
    }
};