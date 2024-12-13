class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        int n = nums.size();

        vector<pair<int, int>> marked;
        for(int i=0 ; i<n ; i++){
            marked.push_back({nums[i], i});
        }
        sort(marked.begin(), marked.end());
        
        for(auto& [num, j] : marked){
            if(nums[j] != -1){
                nums[j] = -1;
                score += num;
                if(j > 0){
                    nums[j-1] = -1;
                }
                if(j < n-1){
                    nums[j+1] = -1;
                }
            }
        }
        return score;
    }
};