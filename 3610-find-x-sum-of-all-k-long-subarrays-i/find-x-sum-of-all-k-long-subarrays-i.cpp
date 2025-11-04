class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> answer(n - k + 1);
        
        for (int i = 0; i <= n - k; ++i) {
            unordered_map<int, int> freq;
            
            // Count frequencies in the current subarray
            for (int j = i; j < i + k; ++j) {
                freq[nums[j]]++;
            }
            
            // Create a vector of pairs (element, frequency)
            vector<pair<int, int>> freqVec(freq.begin(), freq.end());
            
            // Sort by frequency and then by value
            sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second == b.second ? a.first > b.first : a.second > b.second;
            });
            
            // Calculate x-sum
            int sum = 0;
            for (int j = 0; j < min(x, (int)freqVec.size()); ++j) {
                sum += freqVec[j].first * freqVec[j].second;
            }
            
            answer[i] = sum;
        }
        return answer;
    }
};