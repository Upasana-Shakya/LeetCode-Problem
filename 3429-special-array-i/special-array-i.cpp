class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return true;
        }
        else if(n == 2){
            if(nums[0]%2 == nums[1]%2){
                return false;
            }
            else{
                return true;
            }
        }

        for(int i=1 ; i<n-1 ; i++){
            if((nums[i-1]%2) == (nums[i]%2) || (nums[i]%2) == (nums[i+1]%2)) {
                return false;
            }
        }
        return true;
    }
};