#include <iostream>
using namespace std;

struct stack{
    private:
    int a[10000];
    int top = 0;
    
    public:
    
    void push(int x){
        a[top++] = x;
    }
    int pop(){
        return  a[--top];
    }

};