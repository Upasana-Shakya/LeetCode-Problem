class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0;
        int minSum = 0;
        int maxSum = 0;
        for (int num : nums) {
            sum += num;
            if (sum > maxSum) maxSum = sum;
            if (sum < minSum) minSum = sum;
        }
        return abs(maxSum - minSum);
    }
};