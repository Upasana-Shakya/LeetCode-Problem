class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0;
        int n = nums.size();

        for(int i=0 ; i<n ; i++){
            int currSum = nums[i];

            for(int j = i+1 ; j<n && nums[j] > nums[j-1] ; j++){
                currSum += nums[j];
            }

            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};