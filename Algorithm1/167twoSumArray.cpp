class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int,int> num;
        vector<int> ans;
        num[numbers[0]] = 1;
        for(int i=1; i < numbers.size(); i++ ){
            int temp = target - numbers[i];
            if( num[temp] != NULL  ){
                ans.push_back(num[temp]);
                ans.push_back(i+1);
                break;
            }
            num[numbers[i]] = i+1;
        }
        return ans;
    }
};