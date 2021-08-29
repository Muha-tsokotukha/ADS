class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(!nums.size())return ans;
        vector<vector<int>> ranges;

        int j = 1;
        vector<int> temp;
        temp.push_back(nums[0]);
        int sz = nums.size()-1;
        
        while( j <= sz ){
            long long f=nums[j];
            long long f2 = nums[j-1];
            if(  f-f2 != 1 ){
                ranges.push_back( temp );
                temp.clear();
                temp.push_back(nums[j]);
            }else
            temp.push_back(nums[j]);
            j++;
        }
        ranges.push_back( temp);
        
        for(int i =0; i < ranges.size(); i++){
            string t;
            if(  ranges[i].size() == 1  ) t = to_string(ranges[i][0]);
            else{
            int szz = ((ranges[i]).size())-1;
                t = to_string(ranges[i][0]) + "->" + to_string(ranges[i][szz]);
            }  
            ans.push_back(t);
        }
        return ans;
    }
};