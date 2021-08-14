#include <iostream>
using namespace std;

struct queue
{
    private:
    int a[10000];
    int head = 0;
    int tail = 0;
    int sz = 0;
    public:

    bool isfull(){
        return  sz == 10000;
    }
    void add(int x){
        if(isfull){
            cout << "Full" << '\n';
            return;
        }
        tail =( tail + 1)%10000; 
        a[tail++] = x;
        sz++;
    }
    int front(){
        sz--;
        int ans = a[head];
        head = (head+1) % 10000;
        return ans;
    }
};
