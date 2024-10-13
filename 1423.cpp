class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int rightsum = 0 ;
        int leftsum = 0 ;
        int maxsum = 0 ;
        int n = nums.size() ;

        // i have calculated sum of left window and stored it in maxsum 
        for( int i = k-1 ; i >= 0 ; i-- ){
            leftsum += nums[i] ;
            maxsum = leftsum ;
        }

        // now left window ko chota kro and consider about right window 
        int rightindex = n-1 ;
        for( int i = k-1 ; i >= 0 ; i-- ){
            leftsum -= nums[i] ;
            rightsum += nums[rightindex] ;    // yaha rightsum introduce haua hai ... isliye left window choiti h=kiyaband right window ko introduce kiya 
            rightindex -= 1 ;
            maxsum = max( maxsum , rightsum + leftsum ) ;
        }
        return maxsum ;
    }
};
