class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(), nums.end());

        int i=1;

        while(i < nums.size()){
            if(nums[i] > nums[i-1]){
                i++;
                continue;
            }
            else{
                while(nums[i] <= nums[i-1]){
                    nums[i] += 1;
                    count++;
                }
                i++;
            }
        }
        return count;
    }
};