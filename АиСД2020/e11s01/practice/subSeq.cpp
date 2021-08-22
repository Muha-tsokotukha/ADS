class Solution {
public:
    bool isSubsequence(string s, string t) {
        string temp = "";
        int x = 0;
        for(int i =0; i < s.size(); i++){
            int j = x;
            while( j < t.size()  ){
                if( s[i] == t[j]  ){
                    temp += s[i];
                    j++;
                    x = j;
                    break;
                }
                j++;
            }
            if(  j == t.size() && temp != s   )return false;
        }
        return temp == s;
        
    }
};