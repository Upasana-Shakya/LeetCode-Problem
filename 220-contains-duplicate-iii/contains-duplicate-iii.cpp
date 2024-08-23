class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        set<int> set(nums.begin(), nums.end());

        if(valueDiff == 0 && n == set.size()){
            return false;
        }

        for(int i=0 ; i<n ; i++){
            for(int j = i+1 ; j <= i+indexDiff && j<n ; j++){
                if(abs(nums[i] - nums[j]) <= valueDiff){
                    return true;
                }
            }
        }
        return false;
    }
};