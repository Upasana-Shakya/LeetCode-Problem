class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n= nums.size();
        vector<bool>isFliped(n,false);
        int currFlipCount=0;
        int ans=0;

        for(int i=0;i<n;i++){

            if(i>=k && isFliped[i-k]==true){
                currFlipCount--;
            }
            if(currFlipCount % 2==nums[i]){

                if(i+k > n) return -1;

                currFlipCount++;
                ans++;
                isFliped[i]=true;
            }
        }   
        return ans;
    }
};