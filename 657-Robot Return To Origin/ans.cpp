class Solution {
public:
    bool judgeCircle(string moves) {
        int row = 0 , col = 0 ;
        int size = moves.size() - 1 ;
        while( size >= 0){
            if( moves[size] == 'R' ){
                col ++ ;
            }
            else if( moves[size] == 'L' ){
                col -- ;
            }
            else if( moves[size] == 'U' ){
                row -- ;
            }
            else row ++ ;

            size -- ;
        }
        if( row == 0 && col == 0 ) return true ;
        else return false ;

    }
};