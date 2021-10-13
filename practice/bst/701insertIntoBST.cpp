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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* newn = new TreeNode(val);
            return newn;
        }
        if( val  <= root->val  ){
            if(  root->left  )insertIntoBST(root->left,val);
            else{TreeNode* newn = new TreeNode(val);
                root->left = newn;
                return root;
            }
        }   
        else{
            if(  root->right  )insertIntoBST(root->right,val);
            else{TreeNode* newn = new TreeNode(val);
                root->right = newn;
                return root;
            }
        }
        return root;
    }
};