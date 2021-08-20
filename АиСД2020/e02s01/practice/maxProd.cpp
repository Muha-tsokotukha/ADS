
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx1, mx2;
        mx1 = nums[0];
        mx2 = -1e9;
        for(int i = 1; i < nums.size(); i++){
            if( nums[i] >= mx1 ){
                mx2 = mx1;
                mx1 = nums[i];
                continue;
            }
            else if( nums[i] > mx2  ) mx2 = nums[i];
        }
        mx1--;
        mx2--;
        return mx1*mx2; 
    }
};