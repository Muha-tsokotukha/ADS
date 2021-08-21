class Solution {
public:
    // even numbers are winning
    // return n > 1 && n%2 == 0
    
    bool divisorGame(int n) {
        bool a[n+1];
        a[1] = false;
        for(int i = 2; i <= n; i++){
            a[i] = false;
            for( int j = 1; j < i; j++  ){
                if( i%j  == 0 ){
                    if( a[i-j] == false ){
                        a[i] = true;
                        break;
                    }  
                }
            }
        }
        return a[n];
    }
};