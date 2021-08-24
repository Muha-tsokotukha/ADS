class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if( s[i] == '('  ){
                cnt++;
                if( cnt > 1 ){
                    ans+= s[i];
                }
            }
            if( s[i] == ')'  ){
                if(  cnt > 1  ){
                    ans+= s[i];
                }
                cnt--;
            }
            
        }
        return ans;
    }
};