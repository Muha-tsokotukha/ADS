#include <iostream>
using namespace std;

int bin_search(int *a, int x, int l ,int r){
    int m = l+(r-l)/2;
    while( l <= r ){
        if( a[m] == x )return m;
        if( a[m] > x  ){
            r = m-1;
            m = l+(r-l)/2;
            continue; 
        }
        else{
            l = m+1;
            m = l+(r-l)/2;
        }
    }
    return m;
}

int main(){
    int a[8] = {1,3,5,7,10,11,15,17};
    cout << bin_search(a,2,0,7);
}