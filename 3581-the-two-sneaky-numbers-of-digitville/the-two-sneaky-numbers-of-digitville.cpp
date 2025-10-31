class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n-2, 0);

        for(int i=0 ; i<n ; i++){
            freq[nums[i]]++;
        }

        vector<int> res;

        for(int i=0 ; i<n-2 ; i++){
            if(freq[i] == 2){
                res.push_back(i);
            }
        }
        return res;
    }
};