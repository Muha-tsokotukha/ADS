class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int i = 0;
        int j = 0;
        map<char,int> m;
        string ans = "";
        while( j <  magazine.size() && i < ransomNote.size() ){
            if(!m[magazine[j]])m[magazine[j]] = 1;
            else m[magazine[j]]++;
            
            if(  m[ransomNote[i]] > 0 ){
                ans += ransomNote[i];
                m[ransomNote[i]]--;
                i++;
            }
            j++;
        }
        while(i < ransomNote.size()){
            if(  m[ransomNote[i]] > 0 ){
                ans += ransomNote[i];
                m[ransomNote[i]]--;
                i++;
            }else{
                return false;
            }
            
        }
        return ans == ransomNote;
    }
};