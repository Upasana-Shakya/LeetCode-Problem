class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        int prod = 1;
        int count = 1;

        for(auto num : nums){
            prod *= num;
        }
        if(prod == 0){
            for(int i=0 ; i<n ; i++){
                if(nums[i] == 0){
                    for(int j=0 ; j<n ; j++){
                        if(i != j){
                            count *= nums[j];
                        }
                    }
                    ans.push_back(count);
                    count = 1;
                }
                else{
                    ans.push_back(0);
                }
            }
        }
        else{
            for(auto num : nums){
                int temp = prod / num;
                ans.push_back(temp);
            }
        }
        return ans;
    }
};