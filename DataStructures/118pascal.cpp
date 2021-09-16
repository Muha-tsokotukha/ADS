class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        vector<int> temp(1);
        temp[0] = 1;
        ans[0] = temp;
        for(int i = 1; i < numRows; i++){
            vector<int> row(i+1);
            //bool mid = false;
            
            for(int j = 0; j <= i; j++ ){
                if( j == 0 ){
                    row[j] = 1;
                    continue;
                }
                if(  j == i ){
                    row[j] = 1;
                    break;
                }
                row[j] = ans[i-1][j-1] + ans[i-1][j];
            
            }
            ans[i] = row;
        }
        return ans;
    }
};