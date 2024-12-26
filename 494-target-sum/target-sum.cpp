class Solution {
public:
    void solve(vector<int> &nums, int curridx, int currsum, int target, int &res){
        if(curridx == nums.size()){
            if(currsum == target){
                res++;
            }
        }
        else{
            solve(nums, curridx + 1, currsum + nums[curridx], target, res);
            solve(nums, curridx + 1, currsum - nums[curridx], target, res);
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int res = 0;
        solve(nums, 0, 0, target, res);
        return res;
    }
};