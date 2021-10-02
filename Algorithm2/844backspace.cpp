class Solution2pointers {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size()-1; 
        int j = t.size()-1; 
        for(; i >= 0 || j >= 0; i--, j--){
            int cnts = 0;
            while(i >= 0 && (s[i] == '#' || cnts)){
                if( s[i--] == '#' )cnts++;
                else cnts--;
            }

            int cntt = 0;
            while(j >= 0 && (t[j] == '#' || cntt)){
                if( t[j--] == '#' )cntt++;
                else cntt--;
            }

            if(i >= 0 && j >= 0 && s[i] != t[j])
                return false;
        }
        
        return i == j;
    }
};
class Solution3 {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;
        for(int i=0; i < s.size(); i++){
            if(s[i]=='#' && !s1.empty())s1.pop();
            else if(s[i] != '#')s1.push(s[i]);
        }
        for(int i=0; i < t.size(); i++){
            if(t[i]=='#' && !s2.empty())s2.pop();
            else if(t[i] != '#')s2.push(t[i]);
        }
        while( !s1.empty() && !s2.empty()){
            if(s1.top()!=s2.top())return false;
            s1.pop();
            s2.pop();
        }
        if(!s1.empty() || !s2.empty())return false;
        return true;
    }
};

class Solution2 {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size()-1;
        int j = t.size()-1;
        int cnt = 0;
        string ss = "";
        while( i >= 0 ){
            if(s[i] == '#'){
                cnt++;
                i--;
                continue;
            }    
            if(s[i] != '#' && cnt){
                cnt--;
                i--;
                continue;
            }
            ss+=s[i];
            i--;
        }
        cnt = 0;
        string tt = "";
        i = t.size()-1;
        while( i >= 0 ){
            if(t[i] == '#'){
                cnt++;
                i--;
                continue;
            }    
            if(t[i] != '#' && cnt){
                cnt--;
                i--;
                continue;
            }
            tt+=t[i];
            i--;
        }
        return tt==ss;
    }
};