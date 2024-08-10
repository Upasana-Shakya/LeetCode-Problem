class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string, int> mp;

        for(auto word : words){
            mp[word]++;
        }

        vector<pair<int, string>> v;

        auto it = mp.begin();

        while(it != mp.end()){
            v.push_back(make_pair(it->second, it->first));
            it++;
        }

        sort(v.begin(), v.end(), [](const auto& a, const auto& b){
            if(a.first == b.first){
                return a.second < b.second;
            }
            else{
                return a.first > b.first;
            }
        });
        vector<string> ans;

        for(int i=0 ; i<k ; i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};