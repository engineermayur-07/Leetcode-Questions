class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int n = s.size();
        
        int lastA = -1 , lastb = -1 , lastC = -1 ;
        for( int i = 0 ; i < n ; i++ ){

            if( s[i] == 'a' ) lastA = i ;
            if( s[i] == 'b' ) lastb = i ;
            if( s[i] == 'c' ) lastC = i ;

            if( lastA != -1 && lastb != -1 && lastC != -1 ){
                int minAB = min( lastA , lastb ) ;

                count += min( minAB , lastC ) +1 ;
            }

        }
        
        return count;
    }
};