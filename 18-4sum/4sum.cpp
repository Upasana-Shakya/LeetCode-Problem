class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<vector<int>> V;
        set<vector<int>> set;

        sort(nums.begin(),nums.end());

        for(int a=0 ; a<n-3 ; a++)
        {
            for(int b = a+1 ; b < n-2 ; b++){
                long long sum = (long long)target - (long long)nums[a] - (long long)nums[b];
                int c = b + 1 ;
                int d = n-1;
                while(c < d){
                    if(nums[c]+nums[d] < sum){
                        c++;
                    }
                    else if(nums[c]+nums[d] > sum){
                        d--;
                    }
                    else{
                        set.insert({nums[a],nums[b],nums[c],nums[d]});
                        c++;
                        d--;
                    }
                }
            }
        }
        for(auto it : set){
            V.push_back(it);
        }
        return V;
    }
};