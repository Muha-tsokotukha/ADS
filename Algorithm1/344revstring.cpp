class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0; i < s.size()/2;i++){
            char c= s[i];
            s[i] = s[s.size()-1-i];
            s[s.size()-1-i] = c;
        }
    }
};

class Solution2 {
public:
    void reverseString(vector<char>& s) {
        int i = 0; int j = s.size()-1;
        char c;
        while(i <= j){
            c = s[i];
            s[i] = s[j];
            s[j] = c;
            i++;j--;
        }
    }
};
