class Solution {
public:
    int jump(vector<int>& nums) {

        int maxi = 0;
        int cur = 0;
        int jumps = 0;
        for(int i=0; i < nums.size()-1; i++){
            maxi = max(maxi, nums[i] +i );
            if( i == cur ){
                cur = maxi;    
                jumps++;
            }
        }
        
        return jumps;
    }
};