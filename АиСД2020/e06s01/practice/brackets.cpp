#include <iostream>
using namespace std;

struct node
{
    char val;
    node* next;
    node(char c){
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
    void push(char c){
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
    for (int i = 0; i < s.size(); i++)
    {
        if(  (s[i] == ')' && ms.topp() == '(' )  ||  (s[i] == ']' && ms.topp() == '[' ) || (s[i] == '}' && ms.topp() == '{' )  ){
                ms.pop();
                continue;                
            }
            ms.push(s[i]);
        }
    
    if( ms.isEmpty()  ) cout << "true";
    else cout << "false";
}