class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n < 2) return n;
        int a[n+1];
        a[0] = 0;
        a[1] = 1;
        int mx = -1e9;
        for(int i = 2; i <= n; i++){
            if( i%2 == 0 )a[i] = a[i/2];
            else a[i] = a[i/2]+a[i/2+1];
            if( mx < a[i] )mx = a[i];
        }
        return mx;
    }
};