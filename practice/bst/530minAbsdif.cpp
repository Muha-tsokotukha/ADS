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
    int diff = INT_MAX;
    TreeNode *prev = NULL;
    void dfs(TreeNode *root) {
        // moving to the left as much as we can
        if (root->left) dfs(root->left);
        // if we find at least a node before, we update diff
        if (prev) diff = min(diff, abs(prev->val - root->val));
        prev = root;
        // moving to the right as much as we can
        if (root->right) dfs(root->right);
    }
    int getMinimumDifference(TreeNode *root) {
        dfs(root);
        return diff;
    }
};

class Solution_stupidWay {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        helper(root,v);
        int mini = 100000;
        for(int i =0; i < v.size();i++){
            for(int j = i+1; j < v.size();j++){
                if(  abs(v[i]-v[j])<mini  )mini =abs(v[i]-v[j]); 
            }
        }
        return mini;
    }
    void helper(TreeNode* r,vector<int> &v){
        if(!r)return;
        v.push_back(r->val);
        helper(r->left, v);
        helper(r->right, v);
    }
};