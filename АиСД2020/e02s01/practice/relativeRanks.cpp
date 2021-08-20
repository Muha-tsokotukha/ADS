class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int, int> ind;
        priority_queue<int> rank;
        vector<string> ans(score.size());
        for(int i = 0; i < score.size(); i++){
            ind[score[i]] = i; 
            rank.push(score[i]);
            //ans.push_back("");
        }
        int i = 1;
        while(  !rank.empty()   ){
            int x = rank.top();
            rank.pop();
            if( i ==1 ){
                ans[ind[x]] = "Gold Medal";
            }
            else if( i ==2 ){
                ans[ind[x]] = "Silver Medal";
            }
            else if( i ==3 ){
                ans[ind[x]] = "Bronze Medal";
            }
            else{
                ans[ind[x]] = to_string(i) ;
            }
            i++;
        }
        return ans;
    }
};