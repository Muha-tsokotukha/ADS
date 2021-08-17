#include <iostream>
#include <algorithm>
using namespace std;
// rabbit can jump up to k cells forward

int min_cost(int *arr, int n, int k){
    //int prev[n];
    int cost[n];
    cost[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        cost[i] = 1e9;
        for (int j = 0; j < k; j++)
        {
            if(  i-j >= 0){
                if( cost[i-j] + arr[i] < cost[i] ){
                    cost[i] = cost[i-j] + arr[i];
                    //prev[i] = i-j;
                }
            }
        }
       
    }
    return cost[n-1];
}

int main(){
    int a[6] = {0,1,3,1,2,0};
    cout << min_cost(a, 6,3) << '\n';
    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }
    
}