class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int> temp;

        while(nums.size() > 1){
            for(int i=0 ; i<nums.size()-1 ; i++){
                int sum = nums[i]+nums[i+1];
                if(sum > 9){
                    temp.push_back(sum%10);
                }
                else{
                    temp.push_back(sum);
                }
            }
            nums = temp;
            temp.clear();
        }
        return nums[0];
    }
};