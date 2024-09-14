class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(), nums.end());
        int res = 0;
        int j = -1;

        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] != maxEle){
                j = i;
            }
            res = max(res, i-j);
        }
        return res;
    }
};