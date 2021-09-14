class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> seen;
        vector<int> ans;
        seen[nums[0]] = 1;
        for(int i = 1; i < nums.size(); i++ ){
            int temp = target - nums[i];
            if( seen[temp]  ){
                ans.push_back(seen[temp]-1);
                ans.push_back(i);
                break;
            }
            seen[nums[i]] = i+1;
        }
        return ans;
    }
};