class Solution {
public:
    int fib(int n) {
        long long prev = 1;
        long long next = 1;
        if(n == 0) return  0;
        if(  n == 1 || n == 2 ) return prev;
        n--;
        while(n){
            next = prev + next;
            prev = next - prev;
            n--;
        }
        return prev;
    }
};