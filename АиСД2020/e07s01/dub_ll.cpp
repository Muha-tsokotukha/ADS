#include <iostream>
using namespace std;

struct node{
    int val;
    node* next;
    node* prev;
    node(int x){
        this->val = x;
        this->next = NULL;
        this->prev = NULL;
    }
};

struct doubly_ll
{
    private:
    //
    // should add fictional first and(or) last nodes that are null, but can hold pointer to 1st element or last 
    //
    // fictional <-> 1st <-> 2nd <-> 3rd <-> fictionalLast
    //
    node* head;
    node* tail;
    // O(1)
    void _remove(node* x){
        node* z = x->next;
        node* y = x->prev;
        if( z!=NULL)z->prev = y;
        if( y!=NULL)y->next = z;
        else head = tail = z;
    }

    public:
    // O(1)
    void pushback(int x){
        node *newNode = new node(x);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->prev = tail; 
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
    void addAfter(node* x, int y){
        node* newNode = new node(y);
        node* z = x->next;
        x->next = newNode;
        newNode->prev = x;
        newNode->next = z;
        if( z != NULL ) z->prev = newNode; 
    }
    
};

