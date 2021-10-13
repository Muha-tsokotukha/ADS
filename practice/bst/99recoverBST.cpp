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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inorder;
        inorderTrav(inorder, root );
        vector<pair<TreeNode*, TreeNode* >> pairs;
        for(int i =0; i < inorder.size()-1;i++){
            if( inorder[i]->val > inorder[i+1]->val   ){
                pairs.push_back(make_pair( inorder[i], inorder[i+1] ));
            }    
        }
        if( pairs.size() == 1 ){
            int t = pairs[0].first->val; 
            pairs[0].first->val = pairs[0].second->val;
            pairs[0].second->val = t;
        }
        
        else{
            int t = pairs[0].first->val;
            pairs[0].first->val = pairs[1].second->val;
            pairs[1].second->val = t;}
        
    }
    void inorderTrav(vector<TreeNode*> &v,TreeNode* root){
        if(!root)return;
        inorderTrav(v,root->left );
        v.push_back(root);
        inorderTrav(v,root->right );
    }  
};