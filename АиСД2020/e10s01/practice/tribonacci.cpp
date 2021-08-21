class Solution {
public:
    int tribonacci(int n) {
        long long a = 0;
        long long b = 1;
        long long c = 1;
        while(n){
            long long temp = a+b+c;
            a = b; b = c; c = temp;
            n--;
        }
        return a;
    }
};