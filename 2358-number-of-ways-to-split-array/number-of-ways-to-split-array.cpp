class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int count = 0;
        long long sum = 0;
        long long currsum = 0;

        for(auto num : nums){
            sum += num;
        }

        for(int i=0 ; i<nums.size()-1 ; i++){
            currsum += nums[i];
            if(currsum >= sum-currsum){
                count++;
            }
        }
        return count;
    }
};