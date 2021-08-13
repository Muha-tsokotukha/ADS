#include <iostream>
using namespace std;

struct min_heap{
    private:
    int mheap[10000];
    int top = 0;
    
    void min_heapify(){
        int i = top - 1;
        while( i > 0 && mheap[i] < mheap[(i-1)/2] ){
            mheap[i] = mheap[i] + mheap[(i-1)/2];
            mheap[(i-1)/ 2] = mheap[i] - mheap[(i-1)/2];
            mheap[i] = mheap[i] - mheap[(i-1)/2];
            i = (i-1)/2;
        }
    }
    void min_heapify_pop(){
        int i = 0;
        while (1)
        {
            int j = i;
            if(  mheap[2*i+1]< mheap[j] && 2*i+1 < top ){
                j = 2*i+1;
            }
            if(  mheap[2*i+2]< mheap[j] && 2*i+2 < top ){
                j = 2*i+2;
            }
            if( i == j)break;
            mheap[j] = mheap[j] +mheap[i];
            mheap[i] = mheap[j] - mheap[i];
            mheap[j] = mheap[j] - mheap[i];
            i = j;      
        }
    }
    public:
    
    void insert(int x){
        mheap[top] = x;
        top++;
        min_heapify(); 
    }
    
    int get_min(){
        return mheap[0];
    }
    
    int pop(){
        int ans = mheap[0];
        mheap[0] = mheap[--top];
        min_heapify_pop();
        return ans;
    }

    void print(){
        for (int i = 0; i < top; i++)
        {
            cout << mheap[i] << " ";
        }
        cout << '\n';
    }


};




int main(){
    min_heap m;
    m.insert(7);
    m.insert(2);
    m.insert(3);
    m.insert(1);
    m.insert(5);
    m.print();
    cout << m.get_min() << '\n';
    cout << m.pop() << '\n';
    m.print();

}