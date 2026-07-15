class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    
        int n = nums.size() ;
        int sum = nums[0] ;
        int ans = nums[0] ;
        for( int i = 1 ; i < n ; i ++ ){
            if( sum < 0 ){
                sum = nums[i] ;
            }
            else{
                sum += nums[i] ;
            }
            ans = max( sum , ans ) ;
        }
        return ans ;
    }
};