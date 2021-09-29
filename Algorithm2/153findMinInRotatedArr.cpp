class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int mid;
        int r = nums.size()-1;
        bool rotated = false;
        if( nums[0] > nums[r]  )rotated = true;
        if(!rotated)return nums[0];
        
        while( l < r ){
            mid = l + (r-l)/2;
            if( nums[mid] > nums[r] )l = mid+1;
            else r = mid;
        }
        return nums[r];
    }
};