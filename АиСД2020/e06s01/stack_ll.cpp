#include <iostream>
using namespace std;

struct node{
    int val;
    node* next;
    node(int x){
        this->val = x;
        this->next = NULL;
    }
};

struct stack
{
    private:
        node *top = NULL;
    public:
        
        void push(int x){
            node* newNode = new node(x);
            if( top == NULL  ){
                top = newNode;
            }
            else{
                newNode->next = top;
                top = newNode;
            }
        }
        int pop(){
            int ans = top->val;
            top = top->next;
            return ans;
        }
};