class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int index = 0 ;
        vector <int> positive ;
        vector <int> negative ;

        for(int i = 0 ; i < nums.size() ; i++ ){
            if( nums[i] >= 0 ){
                positive.push_back(nums[i]) ;
            }
            else{
                negative.push_back(nums[i]) ;
            }
        }

        
        for( int i = 0 ; i < nums.size() ; i += 2 ){
            nums[i] = positive[index] ;
            nums[i+1] = negative[index] ;
            index++ ;
        }
        return nums ;
    }
};