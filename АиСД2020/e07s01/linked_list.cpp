#include <iostream>
using namespace std;

struct node
{
    int val;
    node* next;
    node(int x){
        this->val = x;
        this->next = NULL;
    }
};


struct linked_list
{
    private:
    node* head = NULL;
    node* tail = NULL;
    public:
    node* getHead(){ // gygygy
        return head;
    }
    // O(1)
    void pushback(int x){
        node *newNode = new node(x);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    // O(n)
    void traverse(){
        node* cur = head;
        while( cur != NULL  ){
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << '\n';
    }
    // O(1)
    void insert( node* x, int y){
        node* newNode = new node(y);
        if(x != NULL){
            newNode->next = x->next;
            x->next = newNode;
        }       
    }
    // O(n)
    void remove(int x){
        node* last;
        node* cur = head;
        while( cur!=NULL  ){
            if(cur->val == x){
                if(last != NULL)
                last->next = cur->next;
                else head = head->next;
            }
            last = cur;
            cur = cur->next;
        }
    }

};



int main(){
    linked_list l;
    l.pushback(1);
    l.pushback(2);
    l.pushback(3);
    l.pushback(4);
    l.traverse();
    node* q = l.getHead();    
    l.insert(q->next->next, 10 );
    l.traverse();
    l.remove(2);
    l.traverse();   
}