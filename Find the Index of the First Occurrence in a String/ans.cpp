class Solution {
public:
    int strStr(string haystack, string needle) {
         
        int size_hay = haystack.size() ;
        int size_needle = needle.size() ;

        size_t index = haystack.find(needle) ;
        if( index == string :: npos ){
            return -1 ;
        }
        else {
            return index ;
        }
    }
};