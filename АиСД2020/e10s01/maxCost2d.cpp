#include <iostream>
#include <vector>
#include <algorithm> // max
using namespace std;



int maxCost( int m, int n,vector<vector<int>> cost){
    int d[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if( i == j && i == 0) d[0][0] = 0;
            else{
                d[i][j] = -1e9;
                if( j > 0 ){
                    d[i][j] = max(d[i][j], d[i][j-1] + cost[i][j] );
                }
                if(i > 0){
                    d[i][j] = max(d[i][j], d[i-1][j] + cost[i][j] );
                }
            }
        }
        
    }
    return d[n-1][m-1];   
}

int main(){
    vector<vector<int>> v = {{1, 2, 100}, {4, 5, 6}, {7, 8, 9}};
    int n = 3;
    int m = 3;
    cout << maxCost(m,n,v);
}