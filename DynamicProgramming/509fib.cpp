class Solution {
public:
    int fib(int n) {
        if(!n)return 0;
        int prev = 1;
        int next = 1;
        n--;
        while(n){
            next = next + prev;
            prev = next - prev;
            n--;
        }
        return prev;
    }
};