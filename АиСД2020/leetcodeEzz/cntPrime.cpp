class Solution {
public:
    int countPrimes(int n) {
        if(!n)return 0;
        bool prime[n+1]; //= {1};
        memset(prime, 1, sizeof prime);
        prime[0] = 0; prime[1] = 0;
        for (int p = 2; p * p <= n; p++){
            if (prime[p] == 1){
                for (int i = p * p; i <= n; i += p)
                    prime[i] = 0;
            }
        }
        int cnt = 0;
        for(int i =0; i < n; i++)if(prime[i])cnt++;
        return cnt;
    }
};