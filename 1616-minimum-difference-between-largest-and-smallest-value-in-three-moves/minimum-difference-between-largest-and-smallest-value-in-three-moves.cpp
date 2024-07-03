class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int ans;

        if(n <= 4){
            ans = 0;
        }
        else{
            ans = min(min(nums[n-4]-nums[0], nums[n-3]-nums[1]), min(nums[n-2]-nums[2], nums[n-1]-nums[3]));
        }
        return ans;
    }
};