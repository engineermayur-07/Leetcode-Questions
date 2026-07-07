class Solution {
public:
    bool isPalindrome(string s) {
        int first = 0 ;
        int last = s.size() - 1 ; 

        while ( first <= last ){
            if( (s[first] < 65 && s[first] > 57) || s[first] < 48 || s[first] > 122 ||(s[first] > 90 && s[first]<97)){
                first ++ ;
                continue ;
            }
            if( (s[last] < 65 && s[last] > 57) || s[last] < 48 || s[last] > 122 ||(s[last] > 90 && s[last] < 97 )){
                last -- ;
                continue ;
            }

            if( s[first] <= 90 && s[first] >= 65 ){
                if(( (s[first] + 32 ) != s[last] && s[first] != s[last]) ) return false ;
            }
            else if( s[first] >= 97 ){
                if(( s[first] - 32 ) != s[last] && s[first] != s[last]) return false ;
            }
            else {
                if( s[first] != s[last] ) return false ;
            }
            first ++ ;
            last -- ;
        }
        return true ;
    }
};