class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int lenpattern = patterns.size() ; 
        
        int count = 0 ;
         
        for( int i = 0 ; i < lenpattern ; i++){
            int ispresent = word.find(patterns[i]) ; 
             if( ispresent != -1 ){
                count ++ ;
             }
            
        }

        return count ;

        
    }
};