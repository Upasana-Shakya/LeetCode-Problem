class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v;
        vector<int> ans;
        unordered_map<int, int> freq;

        for(auto num : nums){
            freq[num]++;
        }

        for(auto i : freq){
            if(i.second > 0){
                v.push_back(make_pair(i.first, i.second));
            }
        }

        sort(v.begin(), v.end(), [](pair<int,int>& a,pair<int,int>&b){
            if(a.second==b.second) return a.first>b.first;
            return a.second<b.second;
        });

        for(int i=0 ; i<v.size() ; i++){
            int k = v[i].second;
            while(k){
                ans.push_back(v[i].first);
                k--;
            }
        }
        return ans;
    }
};