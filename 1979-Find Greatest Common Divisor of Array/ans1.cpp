class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size() ;
        int large = 0 ;
        int small = 10001 ;

        for( int num : nums ){
            if( num > large ) large = num ;
            if( num < small ) small = num ;
        }

        int remainder = small ; 
        while( remainder > 0 ){
            small = remainder ;
            remainder = large % remainder ;
            large = small ;
            
            
        }

        return small ;



    }
};