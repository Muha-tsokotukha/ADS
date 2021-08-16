#include <iostream>
using namespace std;

struct node
{
    int val;
    node* next;
    node(int c){
        this->val = c;
        this->next = NULL;
    }
};



struct stack
{
    private:
    node *top = NULL;
    int sz = 0;
    public:
    bool isEmpty(){
        return sz == 0;
    }
    void push(int c){
        node* temp = new node(c);
        if(top == NULL){
            top = temp; 
            sz++;
        }else{ 
            temp->next = top;
            top = temp;
            sz++; 
    }}
    char topp(){
        if(!isEmpty()){
            return top->val;  
        }
    }
    void pop(){
        top = top->next; 
        sz--;
    }
};

int main(){
    stack ms;
    string s; cin >> s;
    int maxi = 0;
    ms.push(-1);
    for (int i = 0; i < s.size(); i++)
    {
        if( s[i] == '('  ){
            ms.push(i);
        }
        else if(  s[i] == ')' ){
            if(!ms.isEmpty()){
                ms.pop();
                int x = i - ms.topp();
                if(  x > maxi ) maxi = x;
            }
        }
    }
    cout << maxi;
}