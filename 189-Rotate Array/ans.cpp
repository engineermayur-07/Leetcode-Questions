class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if( k == 0 ) return ;
        int size = nums.size() ;
        k = k % size ;
        vector<int> temp1 ;
        vector<int> temp2 ;
        for( int i = 0 ; i < size ; i++ ){
            if( i < ( size - k )){
                temp1.push_back(nums[i]) ;
            }
            else{
                temp2.push_back(nums[i]) ;
            }
        }
        int i = 0 ;
        for( ; i < temp2.size() ; i ++ ){
            nums[i] = temp2[i] ;             
        }
        for( int j = 0 ; j < temp1.size() ; j++ ){
            nums[i] = temp1[j] ;
            i++ ;
        }
          
    }
};