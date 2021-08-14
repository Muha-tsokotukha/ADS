#include <iostream>
using namespace std;

int max(int x, int y){
    if(x > y) return x;
    else return y;
}

bool good(int x, int w, int h, int n){
    return ((x/h)*(x/w)>=n);
}

int search( int w, int h){
    int n;
    int l = 0;
    int r = max(w,h)* sqrt(n);
    int m; 
    while( r - l > 1){
        m = l+(r-l)/2;
        if(good(m,w,h,n)){
            r = m;
        }
        else l = m;
    }
    return r;
}
