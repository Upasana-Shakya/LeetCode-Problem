class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i=0 ; i<n ; i++){
            nums[i] = nums[i] % 2;
        }

        vector<int> prefix(n+1);
        prefix[0] = 1;
        int sum = 0;
        int ans = 0;

        for(int i=0 ; i<n ; i++){
            sum = sum + nums[i];
            if(sum >= k){
                ans = ans + prefix[sum - k];
            }
            prefix[sum]++;
        }
        return ans;
    }
};