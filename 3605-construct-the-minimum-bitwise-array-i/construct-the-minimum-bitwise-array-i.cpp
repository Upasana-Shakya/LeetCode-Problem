class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        for(auto num : nums){
            int temp = -1;

            for(int i=0 ; i<=num ; i++){
                if((i | (i+1)) == num){
                    temp = i;
                    break;
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};