class Solution {
public:
    bool check(vector<int>& nums) {
        int size = nums.size() ;
        for( int i = 0 ; i < size-1 ; i++ ){
            if( nums[i] > nums[i+1] ){
                if( nums[i] < nums[size-1] || nums[0] < nums[size-1] )return false ;
                for( int j = i+1 ; j < size-1 ; j++ ){
                    if( nums[j] > nums[j+1] ) return false ;
                }
            }
        }
        return true ;
    
    }
};