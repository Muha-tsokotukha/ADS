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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // traverse, convert from middle
        vector< int > nodes;
        while(head){
            nodes.push_back(head->val);
            head = head->next;
        }
        TreeNode* root = helper(0, nodes.size()-1, nodes );
        return root;
    }
    TreeNode* helper(int l, int r, vector<int> &v){
        if(  l > r  )return NULL;
        int mid = l+(r-l)/2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = helper(l,mid-1,v);
        root->right = helper(mid+1,r,v);
        return root;
    }
};