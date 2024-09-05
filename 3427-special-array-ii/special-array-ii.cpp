class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<int> count_pairs(nums.size(), 0);

        int cnt = 0;
        for(int i=1 ; i<nums.size() ; i++){
            if(nums[i]%2 == nums[i-1]%2){
                cnt++;
            }
            count_pairs[i] = cnt;
        }

        for(auto q : queries){
            if(count_pairs[q[0]] == count_pairs[q[1]]){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};