class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;
        bool sum_is_odd = 0;
        int cnt[2] = {1, 0};   // cnt[0] for even, cnt[1] for odd
        long long ans = 0;
        for(int x : arr){
            sum_is_odd ^= (x&1); 
            ans += cnt[1-sum_is_odd];
            cnt[sum_is_odd]++;
        }
        return ans % mod;
    }
};