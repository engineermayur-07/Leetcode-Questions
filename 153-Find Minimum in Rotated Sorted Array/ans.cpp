class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size() ;
        int low = 0, high = n-1 ;

        int ans = INT_MAX ;
        while( low <= high ){
            int mid = low + ( high - low )/2 ;

            ans = min( nums[mid] , ans );

            if( nums[low] <= nums[mid] ){
                ans = min(nums[low],ans) ;
                low = mid + 1 ;
            }
            else{
                high = mid-1 ;
            }
        }
        return ans ;
        
    }
};