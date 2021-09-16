class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[nums.size()];
        dp[0] = nums[0];
        if(nums.size() >= 2)dp[1] = nums[1];
        if( nums.size() >= 3 )dp[2] = nums[0] + nums[2];
        
        for(int i=3; i < nums.size(); i++){
            dp[i] = dp[i-2] + nums[i];
            if( dp[i-3] + nums[i]  > dp[i] )dp[i] = dp[i-3] + nums[i];
        }
        
        int ans = dp[nums.size()-1];
        
        if( nums.size() >= 2  )
        
        if(ans < dp[nums.size()-2])ans = dp[nums.size()-2];
        return ans;
    }
};