#include <iostream>
using namespace std;
// rabbit can jump 1 cell or 2 cells forward
int min_cost(int *arr, int n){
    for (int i = 2; i < n; i++)
    {
        int ft = arr[i] + arr[i-1];
        int sn = arr[i] + arr[i-2];
        if(  ft > sn ) arr[i] = sn;
        else arr[i] = ft;
    }
    return arr[n-1];
}

int main(){
    int a[6] = {0,1,3,1,2,0};
    cout << min_cost(a, 6);
}