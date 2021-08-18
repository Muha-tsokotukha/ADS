#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        int i = 0;
        while( i < grid.size() ){
            bool fnd = false;
            int l = 0;
            int r = grid[i].size()-1;
            int m; 
            while(l <= r){
                m =l + (r-l)/2; 
                if( grid[i][m] < 0 ){
                    fnd = true;
                    r = m-1;
                }
                else{
                    l = m + 1;
                }
            }
            if(fnd){
                cnt += ( grid[i].size() - l );
            }
            i++;
        }
        
        return cnt;
        
    }
};