#include <iostream>
using namespace std;

bool good(int t){
    // max(Li) <= min(Ri) 
}

int search(float eps ){
    float m,r,l;
    r= 1e10;
    l = 0;
    eps = 0.000001;  
    while(r -l > eps ){ // needs ref
        m = l+(r-l)/2;
        if(m <= l || m >=r)break;
        if(good(m)){
            r = m;
        }
        else l = m;
    }
    return r;
}



