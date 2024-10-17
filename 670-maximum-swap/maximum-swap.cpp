class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);  // Convert the number to a string
        int n = s.size();
        int maxNum = num;  // Initialize maxNum with the original number

        // Try all pairs (i, j) where 0 <= i < j < n
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(s[i], s[j]);  // Swap the digits at i and j

                maxNum = max(maxNum, stoi(s));  // Update maxNum if needed

                swap(s[i], s[j]);  // Swap back to original
            }
        }

        return maxNum;
    }
};