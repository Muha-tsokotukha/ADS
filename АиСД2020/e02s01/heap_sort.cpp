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
    
    void pop(){
        mheap[0] = mheap[--top];
        min_heapify_pop();
    }

    void print(){
        for (int i = 0; i < top; i++)
        {
            cout << mheap[i] << " ";
        }
        cout << '\n';
    }
};


void heapSort(int *a, int n ){
    min_heap s;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = s.get_min(); 
        s.pop();
    }
    
}






int main(){
    int a[8] = {5,1,7,9,6,3,4,2};
    heapSort(a,8);
    for (int i = 0; i < 8; i++)
    {
        cout << a[i] << " ";
    }
       
}