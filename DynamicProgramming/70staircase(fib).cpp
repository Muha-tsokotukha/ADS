class Solution {
public:
    int climbStairs(int n) {
        if(!n)return 0;
        long long prev = 1;
        long long next = 1;
        //n--;
        while(n){
            next = next + prev;
            prev = next - prev;
            n--;
        }
        return prev;
    }
};