class Solution {
public:
    int mySqrt(int x) {
        
        long long ans = x ;
        while ( ( ans * ans ) > x ){
            ans = ( ans + ( x/ans ) ) / 2 ;
        }
        return int(ans) ;
    }
};