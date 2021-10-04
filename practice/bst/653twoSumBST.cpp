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
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        helper(root, v);
        int i=0;
        map<int,bool> m;
        while(i < v.size()){
            int t = k - v[i];
            if(m[t])return true;
            m[v[i]] = 1;
            i++;
        }
        return false;
    }
    void helper(TreeNode* root, vector<int> &v){
        if(!root)return;
        v.push_back(root->val);
        helper(root->left,v);
        helper(root->right,v);
    }
};