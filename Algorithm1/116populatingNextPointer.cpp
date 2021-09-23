/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution1 {
public:
    Node* connect(Node* root) {
        if( !root  )return NULL;
        vector<Node*> nodes;
        Traverse(root, nodes);
        int i = 2;
        int j = 1;
        nodes[0]->next = NULL;
        while( pow(2,i)-2  <  nodes.size()  ){
            while(j + 1<= pow(2,i) - 2 ){
                nodes[j]->next = nodes[j+1];
                j++;
            }
            nodes[j]->next = NULL;
            j++;
            i++;
        }
        return root;
    }
    vector<Node*> Traverse(Node* root, vector<Node*>& ans) {
        if(!root)return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            if(cur){
                ans.push_back(cur);
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return ans;
    }
};

class Solution2pointers {
public:
    Node* connect(Node* root) {
        if(!root)return NULL;
        Node* cur = NULL;
        Node* preOrder = root; 
        while(preOrder->left){
            cur = preOrder;
            while(cur){
                cur->left->next = cur->right;
                if(cur->next)cur->right->next = cur->next->left;
                cur = cur->next;
            }
            preOrder = preOrder->left;
        }
        return root;
    }
};