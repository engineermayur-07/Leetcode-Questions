class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if( nums.size() == 0 ) return 0 ;
        unordered_set <int> set( nums.begin() , nums.end() ) ;
        int longest = 0 ;

        for( int i : set ){
            if( set.find(i-1) == set.end() ){

                int j = 1 ;
                int current_length = 1 ;
                while( set.find( i + j ) != set.end() ){
                    current_length ++ ;
                    j++ ;
                }
                longest = max( longest , current_length ) ;

            }

        }
        return longest ; 
    }
};