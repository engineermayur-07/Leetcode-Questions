class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int left = 1 ;
        int buy = prices[0] ;
        int ans = 0 ;

        while( left < prices.size() ){
            ans = max( ans , prices[left] - buy ) ;
            buy = min ( buy , prices[left] ) ;

            left ++ ;
            
        }
        return ans ;
    }
};