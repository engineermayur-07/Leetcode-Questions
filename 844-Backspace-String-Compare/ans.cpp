class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int s_ptr = s.size() - 1 ;
        int t_ptr = t.size() - 1 ;
        int s_skip = 0 ;
        int t_skip = 0 ;
         

        while( s_ptr >= 0 || t_ptr >= 0 ){

            while( s_ptr >= 0 ){
                if( s[s_ptr] == '#'){
                    s_skip ++ ;
                    s_ptr -- ;
                }
                else if( s_skip > 0 ){
                    s_ptr -- ;
                    s_skip -- ;
                }
                else break ;
            }

            while( t_ptr >= 0 ){
                if( t[t_ptr] == '#'){
                    t_skip ++ ;
                    t_ptr -- ;
                } 
                else if( t_skip > 0 ){
                    t_ptr -- ;
                    t_skip -- ;
                }
                else break ;
            }
            
            if( s_ptr >= 0 && t_ptr >= 0 ){
                if( s[s_ptr] != t[t_ptr] ) return false ;
            }
            else if( s_ptr >= 0 || t_ptr >= 0 ) return false ;
            

            t_ptr -- ;
            s_ptr -- ;
            
        }
        return true ;
    }
};