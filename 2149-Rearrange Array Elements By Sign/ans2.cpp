class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int positive = 0 ;
        int negative = 1 ;
        vector <int> ans(nums.size()) ;

        for( int i : nums ){
            if( i >= 0 ){
                ans[positive] = i ;
                positive += 2 ;
            }
            else{
                ans[negative] = i ;
                negative += 2 ;
            }
        }
        return ans ;
    }
         
};