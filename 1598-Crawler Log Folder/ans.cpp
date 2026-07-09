class Solution {
public:
    int minOperations(vector<string>& logs) {
        int top = 0 ;
        int size = logs.size() ;
        
        for( int i = 0 ; i < size ; i++ ){
            if( logs[i] == "../" ){
                if( top != 0 ) top -- ;
            }
            else if( logs[i] == "./" ){
                top = top ;
            }
            else top ++ ;
        }
        return top ;
    }
};