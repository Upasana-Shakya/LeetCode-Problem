class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        int maxi = INT_MIN;

        for(int i=0 ; i<n; i++){
            if(maxi < nums[i]){
                maxi = nums[i];
                idx = i;
            }
        }

        int i=0;
        while(i < idx){
            if(nums[i] > nums[i+1]){
                return false;
            }
            i++;
        }
        i++;
        while(i < n && nums[i] == maxi){
            i++;
        }
        while(i < n-1){
            if(nums[i] > nums[i+1]){
                return false;
            }
            i++;
        }
        if(nums[0] < nums[n-1] && idx != n-1){
            return false;
        }
        return true;
    }
};