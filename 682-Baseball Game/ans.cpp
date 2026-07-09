
class Solution {
public:
    int calPoints(vector<string>& operations) {
        int top = 0 ;
        int record[1000] = {0} ;
        int n = operations.size() ;

        for( int i = 0 ; i < n ; i++ ){
            if( operations[i] == "+"){
                record[top] = record[top-1] + record[top-2] ;
                top ++ ;
            }
            else if( operations[i] == "D"){
                record[top] = 2 * record[top-1] ;
                top++ ;
            }
            else if( operations[i] == "C" ){
                top-- ;
            }
            else {
                record[top] = stoi(operations[i]) ;
                top++ ;
            }
        }

        int ans = 0 ;
        for( int i = top-1 ; i >= 0 ; i-- ){
            ans += record[i] ;
        }
        return ans ;
    }
};