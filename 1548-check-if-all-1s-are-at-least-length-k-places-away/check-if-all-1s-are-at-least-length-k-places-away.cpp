class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int count = 0;

        int idx = 0;
        while(idx < nums.size() && nums[idx] != 1){
            idx++;
        }
 
        for(int i=idx+1 ; i<nums.size() ; i++){
            if(nums[i] == 1){
                if(count < k){
                    return false;
                }
                count = 0;
            }
            else{
                count++;
            }
        }
        return true;
    }
};