class Solution {
public:
    int triangularSum(vector<int>& nums) {

        // BRUTE FORCE ---->
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int> temp;

        while(nums.size() > 1){
            for(int i=0 ; i<nums.size()-1 ; i++){
                int sum = nums[i]+nums[i+1];
                temp.push_back(sum%10);
            }
            nums = temp;
            temp.clear();
        }
        return nums[0];

        // // OPTIMISED ------>
        // int n = nums.size();
        // vector<int> temp(n-1);

        // if(n == 1){
        //     return nums[0];
        // }

        // for(int i=0 ; i<n-1 ; i++){
        //     temp[i] = (nums[i]+nums[i+1])%10;
        // }

        // return triangularSum(temp);
    }
};