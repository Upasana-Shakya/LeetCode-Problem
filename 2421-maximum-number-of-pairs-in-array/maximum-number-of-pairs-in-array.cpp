class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> hash(101, 0);
        int ans1 = 0;
        int ans2 = 0;

        for(auto num : nums){
            hash[num]++;
        }

        for(auto i : hash){
            if(i%2 == 1){
                ans2++;
                ans1 += i/2;
            }
            else if(i%2 == 0){
                ans1 += i/2;
            }
        }
        return {ans1, ans2};
    }
};