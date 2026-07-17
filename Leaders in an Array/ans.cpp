class Solution {
public:
    vector<int> leaders(vector<int>& nums) {

        int n = nums.size() - 1 ;
        int last_leader = nums[n] ;
        vector <int> leader ;
        leader.push_back(nums[n]) ;

        for( int i = n ; i >= 0 ; i-- ){
            if( nums[i] > last_leader ){
                leader.push_back( nums[i] ) ;
                last_leader = nums[i] ;
            }
        }

        reverse( leader.begin() , leader.end() ) ;

        return leader ;
    }
};