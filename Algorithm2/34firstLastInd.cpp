class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l,r,mid; l = 0; r = nums.size()-1;
        vector<int> ans(2);
        ans[0] = 100000;ans[1] = -1;
        while(  l <= r  ){
            mid = l + (r-l)/2;
            if( nums[mid] == target ){
                r = mid-1;
                if( ans[0] > mid ){ans[0] = mid;ans[1] = mid;}
            }
            else if( nums[mid] > target )r = mid-1;
            else if(  nums[mid] < target )l = mid+1;
        }
        l = 0; r = nums.size()-1;
        while(  l <= r  ){
            mid = l + (r-l)/2;
            if( nums[mid] == target ){
                l = mid+1;
                if( ans[1] < mid )ans[1] = mid;
            }
            else if( nums[mid] > target )r = mid-1;
            else if(  nums[mid] < target )l = mid+1;
        }
        if(ans[0] == 100000)ans[0] = -1;
        return ans;
    }
};