class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto num : nums){
            if(num % 2 == 0){
                mp[num]++;
            }
        }

        vector<pair<int, int>> v;

        auto it = mp.begin();
        while(it != mp.end()){
            v.push_back(make_pair(it->second, it->first));
            it++;
        }

        if(v.size() == 0){
            return -1;
        }
        sort(v.begin(), v.end(), [](const auto& a, const auto& b){
            if(a.first == b.first){
                return a.second < b.second;
            }
            else{
                return a.first > b.first;
            }
        });

        auto i = v.begin();

        return i->second;
    }
};