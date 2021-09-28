class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool fnd = false;
        for(int i=0; i < matrix.size(); i++){
            int l = 0;
            int r = matrix[i].size()-1;
            int mid;
            bool less = false;
            while(  l <= r ){
                mid = l + (r-l)/2;
                if( matrix[i][mid] == target ){fnd =  true; break;}
                else if(  matrix[i][mid] > target ){
                    r = mid - 1;
                    less = true;
                }
                else l = mid + 1;
            }
            if(fnd)break;
            if(less) break;
        }
        return fnd;
    }
};