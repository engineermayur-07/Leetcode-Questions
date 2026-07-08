class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0 ;
        string ans = "" ;
        int n1 = num1.size() -1 ;
        int n2 = num2.size() -1 ;
        while( n1 >= 0 || n2 >= 0 || carry ){
            int sum = carry ;
            if( n1 >= 0 ){
                sum += num1[n1] - '0' ;
                n1 -- ;
            }
            if( n2 >= 0 ){
                sum += num2[n2] - '0' ;
                n2 -- ;
            }
             ans += (sum % 10) + '0' ; // ans += to_string(sum%10) 
             carry = (sum/10) ;

        }
        reverse( ans.begin() , ans.end() ) ;
        return ans ;
    }
};