class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        long long count = 0;

        unordered_map<int, int> mp;

        for(auto num : nums){
            int hcf = gcd(num, k);
            int req = k/hcf;
            for(auto it : mp){
                if(it.first % req == 0){
                    count += it.second;
                }
            }
            mp[hcf]++;
        }
        return count;
    }
};