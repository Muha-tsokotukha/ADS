class Solution { //52ms
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> seen;
        for(int i= 0; i < nums.size(); i++){
            if( seen[nums[i]]  )return true;
            seen[nums[i]] = true;
        }
        return false;
    }
};

class Solution2 { //40ms
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> seen;
        for(int i= 0; i < nums.size(); i++){
            seen.insert(nums[i]);
        }
        return !(seen.size()==nums.size());
    }
};