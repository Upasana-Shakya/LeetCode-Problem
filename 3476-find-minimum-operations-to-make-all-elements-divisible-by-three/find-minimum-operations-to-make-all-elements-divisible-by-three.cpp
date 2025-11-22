class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();

        int res = 0;
        for(int i=0 ; i<n ; i++){
            if(nums[i]%3 == 2){
                res++;
            }
            else{
                res += (nums[i]%3);
            }
        }
        return res;
    }
};