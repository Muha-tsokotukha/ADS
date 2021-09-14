class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSum(nums);
    }
    
    int maxSum(vector<int>& nums){
        int mx_global = nums[0];
        int mx_cur =nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if(  mx_cur + nums[i] > nums[i]    )
            mx_cur =  mx_cur + nums[i];
            else mx_cur = nums[i];

            if(mx_global < mx_cur )
                mx_global = mx_cur;

        }
        return mx_global;

    }

};


class Solution2 { // identical, but without function and 0ms
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