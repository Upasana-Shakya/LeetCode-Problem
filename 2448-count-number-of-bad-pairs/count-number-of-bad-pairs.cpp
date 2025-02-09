class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i=0 ; i<n ; i++){
            int diff = i - nums[i];
            int goodPairs = mp[diff];

            res += i - goodPairs;
            mp[diff] = goodPairs + 1;
        }
        return res;
    }
};