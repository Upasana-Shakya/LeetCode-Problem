class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<pair<int, int>> hash;
        vector<int> ans;

        for(auto num : nums){
            mp[num]++;
        }

        auto it = mp.begin();

        while(it != mp.end()){
            hash.push_back(make_pair(it->second, it->first));
            it++;
        }

        sort(hash.begin(), hash.end(), greater<pair<int, int>>());

        for(int i=0 ; i<k ; i++){
            ans.push_back(hash[i].second);
        }
        
        return ans;
    }
};