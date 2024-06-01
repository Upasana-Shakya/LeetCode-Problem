class Solution {
public:
    void solve(vector<int> &nums, int i, vector<vector<int>> &ans){
        //Base Case
        if(i >= nums.size()){
            ans.push_back(nums);
            return ;
        }

        for(int j=i ; j<nums.size() ; j++){
            //Swap
            swap(nums[i], nums[j]);
            //Recursive Call
            solve(nums, i+1, ans);
            //Backtrack
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int i=0;

        solve(nums, i, ans);

        return ans;
    }
};