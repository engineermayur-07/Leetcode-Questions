class Solution {
public:

        int getvalue( char roman ) {
            switch (roman) {
                case 'I' : return 1 ;
                case 'V' : return 5 ;
                case 'X' : return 10 ;
                case 'L' : return 50 ;
                case 'C' : return 100 ;
                case 'D' : return 500 ;
                case 'M' : return 1000 ;
            }
            return 0 ;
        }
    int romanToInt(string s) {

        int n = s.size() ;
        int sum = 0 ;

        for( int i = 0 ; i < n ; i++ ){
            int temp = getvalue(s[i]) ;
            if( i < n-1 && temp < getvalue(s[i+1]) ){
                sum -= temp ;
            }
            else sum += temp ;
        }

        return sum ;
    }
};