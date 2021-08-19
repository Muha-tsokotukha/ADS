#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next; 
    }
};

class Solution2 { // doesnt make sense
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        while( temp != NULL  ){
            node->val = temp->val;
            if(temp->next == NULL){
                node->next = NULL;
                break;
            }
            node = temp;
            temp = temp->next;
        }
    }
};