class Solution {
public:
    bool isPalindrome(int x) {

        if( x < 0 || (x%10 == 0 && x != 0 )) return false ;
         
        int half_reverse = 0 ;
         
        while( half_reverse < x ){
            half_reverse = (half_reverse*10) + (x%10) ;   
            x = x/10 ;
        }
        return ( half_reverse == x || x == half_reverse/10 )  ;
        
    }
};