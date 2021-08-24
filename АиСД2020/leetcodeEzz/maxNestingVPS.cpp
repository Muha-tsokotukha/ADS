class Solution {
public:
    int maxDepth(string s) {

        int i = s.size()-1;
        int mx = 0;
        int cnt = 0;
        while(i >= 0 ){
            if( s[i] == ')' )cnt++;
            if(  s[i] == '(' ){
                if( mx < cnt ){
                    mx = cnt;
                }
                cnt--;
            }
            i--;
        }
        
        return mx;
    }
};