#include <iostream>
#include <algorithm>
using namespace std;
// O(n*m)
int diff(string s, string t){
    int n = s.size(); int m = t.size();
    int a[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if( i == 0 || j == 0){
                a[i][j] = i+j; // init 
                continue;
            }
            if( s[i-1] == t[j-1]){
                a[i][j] = a[i-1][j-1];
            }else{
                a[i][j] = min(a[i-1][j],a[i][j-1] ) ;
                a[i][j] = min(a[i-1][j-1], a[i][j]) + 1; // min of upper, left and upper left cells
            }

        }
    }
    return a[n-1][m-1];

}
int main(){
    string s,t; s = "kotik"; t = "korzik";
    cout << diff(s,t);
}   