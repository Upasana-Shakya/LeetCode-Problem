class Solution {
public:
    int shortestSubarray(vector<int>& nums, int target) {
        int res = INT_MAX;
        long long curSum = 0;
        deque<pair<long long, int>> q;  // (prefix_sum, end_idx)
        
        for (int r = 0; r < nums.size(); r++) {
            curSum += nums[r];
            
            if (curSum >= target) {
                res = min(res, r + 1);
            }
            
            // Find the minimum valid window ending at r
            while (!q.empty() && curSum - q.front().first >= target) {
                auto [prefix, endIdx] = q.front();
                q.pop_front();
                res = min(res, r - endIdx);
            }
            
            // Validate the monotonic deque
            while (!q.empty() && q.back().first > curSum) {
                q.pop_back();
            }
            q.push_back({curSum, r});
        }
        
        return res == INT_MAX ? -1 : res;
    }
};