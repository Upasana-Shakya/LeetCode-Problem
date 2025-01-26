class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int tsum = accumulate(nums.begin(), nums.end(), 0);

        int lsum = 0;
        int rsum = tsum;

        int res = 0;

        for(int i=0 ; i<n-1 ; i++){
            lsum += nums[i];
            rsum -= nums[i];

            if((lsum - rsum)%2 == 0){
                res++;
            }
        }
        return res;
    }
};