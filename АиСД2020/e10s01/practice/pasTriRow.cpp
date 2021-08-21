class Solution {
public:
    vector<vector<int>> helper(int numRows) {
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
            
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> v = helper(rowIndex+1);
        return v[rowIndex];
    }
};
//  catalan
class Solution2 {
public:
    vector<int> getRow(int rowIndex) {
        ll prev = 1;
        vector<int> result;
        result.push_back(prev);
        
        for(int i = 1; i<=rowIndex; i++) {
            
            ll temp = prev * (rowIndex - i + 1)/i;
            result.push_back(temp);
            prev = temp;
        }
        
        return result;
    }
};
//Approach-2 (Using Binomial Coefficient)
class Solution {
public:
    long binomialCoeff(int n, long k)
    {
        long res = 1;
        if (k > n - k)
        k = n - k;
        for (long i = 0; i < k; ++i)
        {
            res *= (n - i);
            res /= (i + 1);
        }
    return res;
    }
    vector<int> getRow(int rowIndex) {
        vector<int> my_vec;
        for(long j = 0; j <= rowIndex; j++)
                my_vec.push_back(binomialCoeff(rowIndex, j));

        return my_vec; 
    }
};