class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        for(int i=0 ; i<n ; i++){
            unordered_set<int> evenst, oddst;

            for(int j=i ; j<n ; j++){
                if(nums[j]%2 == 0){
                    evenst.insert(nums[j]);
                }
                else{
                    oddst.insert(nums[j]);
                }
                if(evenst.size() == oddst.size()){
                    res = max(res, j-i+1);
                }
            }
        }
        return res;
    }
};