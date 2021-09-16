class Solution {
public:
    bool canJump(vector<int>& nums) {
        if( nums.size() == 1 )return true;
        bool a[nums.size()];
        memset(a, false, sizeof(a));
        a[0] = true;
        for(int i=0; i < nums.size(); i++){
            if(!a[i] )continue;
            int temp = nums[i];
            while( temp  ){
                if(  temp + i  == nums.size()-1  )return true;
                else if(temp + i < nums.size())a[temp + i] = true;
                temp--;
            }
        }
        return a[nums.size()-1];
    }
};


class Solution2 { // bfs TL
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)return true;
        bool can[nums.size()];
        can[nums.size()-1] = false;
        queue<int> q;
        q.push(0);
        map<int, bool> seen;
        seen[0] = true;
        while( !q.empty()  ){
            int x = q.front();
            can[x] = true;
            seen[x] = true;
            q.pop();
            int temp = nums[x];
            while( temp){
                if( x + temp <nums.size() && !seen[x + temp]  ){
                    q.push(x+temp);
                }
                temp--;
            }
        }
        return can[nums.size()-1];
    }
};