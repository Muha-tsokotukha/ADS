#include <iostream>
#include <map>
using namespace std;

map<long long, long long> memo;
// n <= 92
long long fib(int n){
    if(n <= 2) return 1;
    else if( memo[n] != NULL ){
        return memo[n];
    }
    else{
        long long f = fib(n-1) + fib(n-2);
        memo[n] = f;
        return memo[n];
    }
}


int main(){
    int n; cin >> n;
    cout << fib(n);
}