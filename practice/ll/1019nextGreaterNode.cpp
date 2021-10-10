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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        stack<int> data;
        int n;
        while( head ){
            data.push(head->val);
            head = head->next;
        } 
        n = data.size();
        vector<int> ans(n);
        int i = n-1;
        while( !data.empty() ){
            int x = data.top(); data.pop();
            while( !st.empty() && x >= st.top() ){
                st.pop();
            }
            if(st.empty()){
                ans[i] = 0;
                st.push(x);
            }else{
                ans[i] = st.top();
                st.push(x);
            }
            i--;
        }
        return ans;
    }
};
















class Solution2 { // O(n^2)
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        while( head ){
            ListNode* cur = head->next;
            while(cur){
                if( cur->val > head->val ){
                    ans.push_back(cur->val);
                    break;
                }
                cur = cur->next;
            }
            if(!cur)ans.push_back(0);
            head = head->next;
        }
        return ans;
    }
};