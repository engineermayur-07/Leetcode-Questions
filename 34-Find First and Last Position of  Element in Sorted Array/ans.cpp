class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1} ;
        int n = nums.size() ; 

        int high = n - 1 ;
        int low = 0 ;
        int mid = 0 ;
        while( low <= high ) {
            mid = low + ( high - low )/2 ; 
            if( nums[mid] == target ){
                ans[0] = mid ;
                high = mid - 1 ;
            }
            if( nums[mid] < target ){
                low = mid + 1 ;
            }
            if( nums[mid] > target ){
                high = mid - 1 ;
            }
        }
        low = 0 ;
        high = n - 1 ;
        while( low <= high ) {
            mid = low + ( high - low )/2 ; 
            if( nums[mid] == target ){
                ans[1] = mid ;
                low = mid + 1 ;
            }
            if( nums[mid] < target ){
                low = mid + 1 ;
            }
            if( nums[mid] > target ){
                high = mid - 1 ;
            }
        }
        return ans ;
    }
};