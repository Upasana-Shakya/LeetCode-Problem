class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0);

        for(int i=0 ; i<nums.size() ; i++){
            freq[nums[i]]++;
        }

        int maxi = *max_element(freq.begin(), freq.end());
        int res = 0;

        for(int i=1 ; i<101 ; i++){
            if(freq[i] == maxi){
                res += freq[i];
            }
        }
        return res;
    }
};