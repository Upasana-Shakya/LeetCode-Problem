class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;
        for(auto num : nums){
            maxi = max(num, maxi);
        }

        vector<int> hash(maxi+1, 0);

        for(auto num : nums){
            hash[num]++;
        }

        for(int i=0 ; i<maxi+1 ; i++){
            if(hash[i] > 2){
                return false;
            }
        }
        return true;
    }
};