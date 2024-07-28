class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int index = 0;

        for(int i=0 ; i<n ; i++){
            if(index < i){
                return false;
            }
            index = max(index, nums[i]+i);
            if(index == n-1){
                return true;
            }
        }
        return true;;
    }
};