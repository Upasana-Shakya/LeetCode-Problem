class Solution {
public:
    int atMost(vector<int>& nums, int k){
        unordered_map<int, int> mp;
        int n = nums.size();
        int ans = 0;
        int left = 0;
        int right = 0;

        while(right < n){
            mp[nums[right]]++;
            while(mp.size() > k){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            ans += right - left + 1;
            right++;
        }

        
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};