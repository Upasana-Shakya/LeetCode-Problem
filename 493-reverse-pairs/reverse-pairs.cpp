class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        vector<long long> arr;

        for(int i=n-1 ; i>=0 ; i--){
            // No. of elements in arr that are smaller than nums[i]
            count += lower_bound(arr.begin(), arr.end(), nums[i]) - arr.begin();

            // arr.insert() stores the elements in sorted form. 
            arr.insert(lower_bound(arr.begin(), arr.end(), 2*(long long)nums[i]), 2*(long long)nums[i]);

        }
        return count;
    }
};