class Solution {
public:
    string reverseWords(string s) {
        int i =0;
        int j = 0;
        int l = 0;
        string ans = "";
        
        while( i < s.size()  ){
            l = i;
            while( s[j] != ' '){
                j++;
                i++;
                if(  j == s.size() )break;
            }
            
            j--;
            while( j >= l){
                ans+= s[j];
                j--;
            }
            i++;
            j = i;
            if(  i <= s.size()  )ans += " ";
        }
        return ans;
    }
};