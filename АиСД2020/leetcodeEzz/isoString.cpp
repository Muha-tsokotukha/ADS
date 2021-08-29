class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if( s == t )return true;
        map<char, bool> used;
        map<char, int> let;
        string ans = "";
        for(int i =0; i < s.size(); i++){
            if(  let[s[i]] == NULL  ){
                if( used[t[i]] )return false;
                let[s[i]] = t[i];
                used[t[i]] = true;
            }
            ans += let[s[i]];
        }
        return ans == t;
    }
};