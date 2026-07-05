class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max = LONG_MIN ;
        long long sec_max = max ;
        long long third_max = max ;

        int size = nums.size() ;

        for( int i = 0 ; i < size ; i++ ){

            if( nums[i] > max ) {
                third_max = sec_max ;
                sec_max = max ;
                max = nums[i] ;
            }

            if( nums[i] > sec_max && nums[i] != max){
                third_max = sec_max ;
                sec_max = nums[i] ;
            }

            if( nums[i] > third_max && nums[i] != max && nums[i] != sec_max){
                third_max = nums[i] ;
            }

        }

        if( size < 3 ) return max ;
        
        if( third_max == sec_max || third_max == max || third_max == LONG_MIN  ) return max ;

        return third_max ;
        
    }
};