class Solution {
public:
    string addBinary(string a, string b) {
            int right_a = a.size() - 1 ;
            int right_b = b.size() - 1 ;
            string ans = "" ;
            int carry = 0 ;

            while( right_a >= 0 || right_b >= 0 || carry > 0){

                int sum = carry ;

                if( right_a >= 0 ){
                    sum += a[right_a] - '0' ;
                    right_a-- ;
                }

                if( right_b >= 0 ){
                    sum += b[right_b] - '0' ;
                    right_b-- ;
                }

                ans += to_string(sum%2) ;
                carry = sum/2 ;
            }

            reverse( ans.begin() , ans.end() ) ;
            return ans ;
         
    }     
};