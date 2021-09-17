class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = nums[0];
        int CurMx = nums[0];
        for(int i= 1;i < nums.size();i++){
            if( CurMx + nums[i] > nums[i]  ){
                CurMx = CurMx + nums[i];
            }else{
                CurMx = nums[i];
            }
            if( CurMx > mx  )mx = CurMx;
        }
        return mx;
    }
};