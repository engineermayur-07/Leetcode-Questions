class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size() ;
        int cols = matrix[0].size() ;
        vector<int> array(rows*cols) ;
        int top = 0 ;
        int bottom = rows - 1 ;
        int left = 0 ;
        int right = cols - 1 ;
        int count = 0 ;
        while( bottom >= top && right >= left){

            for( int i = left ; i <= right ; i++ ){
                array[count] = matrix[top][i] ;
                count++ ;
            }
            top++ ;

            for( int i = top ; i <= bottom ; i++){
                array[count] = matrix[i][right] ;
                count++ ;
            }
            right-- ;
            
            if( top <= bottom ){
                for( int i = right ; i >= left ; i--){
                    array[count] = matrix[bottom][i] ;
                    count++ ;
                }
                bottom-- ;
            }

            if( left <= right ){
                for( int i = bottom ; i >= top ; i-- ){
                    array[count] = matrix[i][left] ;
                    count++ ;
                }
                left++ ;
            }

        }
        return array ;
        
    }
};