class Solution {
public:
    int findGCD(vector<int>& nums) {
        
        int large = 0 ;
        int small = 10001 ;

        for( int num : nums ){
            if( num > large ) large = num ;
            if( num < small ) small = num ;
        }

        return __gcd( large , small ) ;



    }
};