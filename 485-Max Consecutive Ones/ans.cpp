class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0 ;
        int left = 0 ;
        int right = 0 ;
        for( int i = 0 ; i < nums.size() ; i++ ){
            if( nums[i] == 0 ){
                ans = max( ans , left - right ) ;
                left = i  ;
                right = i  ;         
            }
            else{
                left ++ ;
            }
        }
        ans = max( ans , left - right ) ;
        return ans;
    }
};