class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int count = 0;

        // // Gives TLE--------------------------->
        // for(int i=0 ; i<n ; i++){
        //     int sum = 0;
        //     for(int j=i ; j<n ; j++){
        //         sum += nums[j];            
        //         if(sum == goal){
        //             count++;
        //         }
        //     }
        // }

        unordered_map<int, int> pref_sum;
        pref_sum[0] = 1;
        int sum = 0;

        for(auto num : nums){
            sum += num;

            // check if there is a subarray whose sum == goal
            if(pref_sum.find(sum - goal) != pref_sum.end()){
                count += pref_sum[sum - goal];
            }
            pref_sum[sum]++;
        }
        return count;
    }
};