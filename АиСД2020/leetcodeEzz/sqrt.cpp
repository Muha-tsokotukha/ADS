class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 )return 0;
        long long l = 0; long long r = x;
        long long m ;
        while( l <= r   ){
            m = l + (r-l)/2;
            if( m*m == x ){
                return m;
                break;}
            if( m*m < x ){
                l = m+1;
            }
            if( m*m > x ){
                r = m-1;
            }
        }
        return r;
    }
};