class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size() ;
        if( duration == 0 ) return 0 ;
        int ans = duration ;
        for( int i = 1 ; i < n ; i++ ){
            if( (timeSeries[i] - timeSeries[i-1] <= duration) ){
                ans = ans + timeSeries[i] - timeSeries[i-1] ;
            }
            else {
                ans += duration ;
            }
        }
        return ans ;
    }
};