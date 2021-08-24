
// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    stack<int> ans;    
    TreeNode* increasingBST(TreeNode* root) {
        adding(root);
        TreeNode* head = new TreeNode(ans.top());
        ans.pop();
        TreeNode* cur = head;
        while(!ans.empty()){
            TreeNode* newn = new TreeNode(ans.top());
            ans.pop();
            cur->right = newn;
            cur = cur->right;
        }
        return head;
    }
    
    void adding(TreeNode* x){
        if( x == NULL  )return;
        adding(x->right); 
        ans.push(x->val);
        adding(x->left);
    }
};