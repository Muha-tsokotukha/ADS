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
    bool iss = 1;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        isSameTre(p,q);
        return iss;
    }
    
    void isSameTre(TreeNode* p, TreeNode* q) {
    if( (p == NULL && q != NULL )||(p != NULL && q == NULL )  ){iss =  false;return;}
        if( p == NULL && q == NULL  )return;
        if(  p->val != q->val  ){iss = false;return;}
        isSameTre(p->left, q->left);
        isSameTre(p->right, q->right);
    }
};

// maybe should've solved with stack