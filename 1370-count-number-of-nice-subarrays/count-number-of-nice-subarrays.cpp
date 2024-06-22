class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n+1);
        prefix[0] = 1;

        for(int i=0 ; i<n ; i++){
            nums[i] = nums[i] % 2;
        }

        int sum = 0;
        int ans = 0;

        for(auto num : nums){
            sum += num;
            if(sum >= k){
                ans += prefix[sum - k];
            }
            prefix[sum]++;
        }
        return ans;
    }
};