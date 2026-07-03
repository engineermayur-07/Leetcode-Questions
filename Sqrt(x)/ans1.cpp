class Solution {
public:
    int mySqrt(int x) {
        
        for( int i = 0 ; i <= ( x/2 + 1 ) ; i++ ){
            int ans = i ;
            if( (i+1) > ( x/(i+1) ) ) return i ;
            if( (i+1) == ( x/(i+1) ) ) return i+1 ;
        }
        return -1 ;
    }
};