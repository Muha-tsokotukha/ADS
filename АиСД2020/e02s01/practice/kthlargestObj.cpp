// needs debugging
// may be some issues with cycles
// and pointers
class KthLargest {
public:
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
    
    node* head = new node(-1000000) ;
    int num ;
    int last = 0;
    int sz = 0 ;
        KthLargest(int k, vector<int>& nums) {
        this->num = k;
        while( k ){
            maxiAppend( nums);
            k--;
        }
    }

    
    void clearing(){
        node* cur = head->next;
        int i =0;
        while( i < this->num ){
            cur = cur->next;
            i++;
        }
        cur->next = NULL;
        this->last = 100; //cur->val;
        this->sz = this->num;
    }
    
    void append_node(int x){
        if(  head->next = NULL ){
            node* newnode = new node(x);
            head->next = newnode; 
            newnode->prev = head;
            this->sz++;
            return;
        }
        node* cur = head->next;
        while(  cur != NULL  ){
            if(  cur->val <= x  ){
                node* newnode = new node(x);
                cur->prev->next = newnode;
                newnode->next = cur;
                newnode->prev = cur->prev;
                cur->prev = newnode;
                this->sz++;
                break;
            }
            cur = cur->next;
        }
        if(  this->sz > this->num  )clearing();
    }
    
    void maxiAppend(vector<int>& v ){
        int mx = -1e9;
        int ind = 0;
        for(int i = 1; i < v.size(); i++){
            if(v[i] == -100000) continue;
            if(  mx < v[i] ){
                mx = v[i];
                ind = i;
            }
        }
        v[ind] = -100000;
        append_node(mx);
    }
    
    
    int add(int val) {
        if( val <= this->last  )return this->last;
        append_node(val);
        return this->last;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */