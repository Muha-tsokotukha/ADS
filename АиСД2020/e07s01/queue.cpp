#include <iostream>
using namespace std;


struct node{
    int val;
    node* next;
    node(int x){
        this->val = x;
        next = NULL;
    }
};

struct queue
{
    private:
    node* head;
    node* tail = head;
    public:
    
    void add(int x){
        node* newNode = new node(x);
        tail->next = newNode;
        tail = newNode;
    }
    void remove(){
        node* x = head->next;
        head->next = x->next;
        if(isEmpty()) tail = head;
    }
    int front(){
        return head->next->val;
    }
    bool isEmpty(){
        return head->next == NULL; 
    }
};

int main(){
    queue q;
    q.add(1);
    q.add(2);
    q.add(3);
    q.add(4);
    cout << q.front() << '\n'; q.remove();
    cout << q.front() << '\n'; q.remove();
    cout << q.front() << '\n'; q.remove();
    cout << q.front() << '\n'; q.remove();
    cout << q.isEmpty();
}
