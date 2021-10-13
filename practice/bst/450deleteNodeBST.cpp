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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return NULL;
        if(root->val == key){
            if( !root->left && !root->right )return NULL;
            if( !root->left && root->right  )return root->right;
            if( root->left && !root->right  )return root->left;
            
            TreeNode* cur = root->right;
            while(cur->left)cur = cur->left;
            root->val = cur->val;
            root->right = deleteNode(root->right, root->val);
        }
        
        if( root->val > key )root->left = deleteNode(root->left, key);
        if( root->val < key )root->right = deleteNode(root->right, key);
        
        return root;
    }
};