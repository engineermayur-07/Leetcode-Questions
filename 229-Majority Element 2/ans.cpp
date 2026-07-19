class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int count1 = 0 ; 
        int candidate1 = INT_MIN ;
        int count2 = 0 ;
        int candidate2 = INT_MIN ;
        int n = nums.size() ;
        vector <int> result ;

        for( int i : nums ){

           
            if( i == candidate1 ) {
                count1 ++ ;
            }

            else if( i == candidate2 ){
                count2 ++ ;
            }

            else if( count1 == 0 ){
                candidate1 = i ;
                count1 = 1 ;
            }

            else if( count2 == 0 ) {
                count2 = 1 ;
                candidate2 = i ;
            }
           
            else {
                count1 -- ;
                count2 -- ;
            }

        }
        
        count1 = 0 ; count2 = 0 ;

        for( int i : nums ){
            if( i == candidate1 ) count1 ++ ;
            if( i == candidate2 ) count2 ++ ;
        }

        
        if( count1 > n/3 ) result.push_back( candidate1 ) ;

        if( count2 > n/3 ) result.push_back( candidate2 ) ;

        return result ;

       
         
    }
};