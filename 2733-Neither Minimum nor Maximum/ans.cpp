class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {

        int max = 0 ;
        int min = 0 ;

        int size = nums.size() ;

        if( size < 3 ) return -1 ;

        for( int i = 0 ; i < size ; i++ ){

            if( nums[i] > nums[max] ){     
                max = i ;
            }

            if( nums[i] < nums[min] ){
                min = i ;
            }
        }

        for( int i = 0 ; i < size ; i++ ){

            if( nums[i] != nums[min] && nums[i] != nums[max]){
                return nums[i] ;
            }

        }

        return -1 ;
             
    }
};