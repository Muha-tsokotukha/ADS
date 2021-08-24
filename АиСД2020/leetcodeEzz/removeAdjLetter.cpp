class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for(int i=s.size()-1; i >= 0; i--){
            if( !stk.empty() &&  s[i] == stk.top() )stk.pop();
            else stk.push(s[i]);
        }
        string ans = "";
        while(!stk.empty()){
            ans+= stk.top(); 
            stk.pop();
        }
        return ans;
    }
};