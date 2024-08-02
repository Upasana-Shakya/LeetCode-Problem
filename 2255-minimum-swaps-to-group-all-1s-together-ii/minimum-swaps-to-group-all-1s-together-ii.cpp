class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = count(nums.begin(), nums.end(), 1);

        if(ones == 0){
            return 0;
        }

        vector<int> nums1(nums.begin(), nums.end());
        for(int i=0; i<ones-1; i++){
            nums1.push_back(nums[i]);
        }
        int zeros=0;
        for(int i=0; i<ones; i++){
            if(nums[i]==0) zeros++;
        }
        int i=0; int j=ones-1;

        int ans=zeros;
        while(i<nums1.size() && j<nums1.size()-1){
            if(nums1[i]==0) zeros--;
            if(nums1[j+1] == 0) zeros++;
            i++;
            j++;
            ans=min(ans, zeros);
        }

        return ans;
        
    }
};