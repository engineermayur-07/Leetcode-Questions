class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        sort( nums.begin() , nums.end() ) ;
        if( nums.empty() ) return 0 ;

        int longest = 1 ;
        int current_length = 1 ;

        for( int i = 1 ; i < nums.size() ; i++ ){
            
            if( nums[i] == nums[ i-1 ] ) continue ; 
            if( nums[i-1] + 1 == nums[i]  ) {
                current_length ++ ;
                longest = max( current_length , longest ) ;
            }
            else current_length = 1 ;
        }

        return longest ;
    }
};