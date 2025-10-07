class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size(), 1);
        set<int> temp;
        unordered_map<int, int> mp;

        for(int i=0 ; i<rains.size() ; i++){
            if(rains[i] > 0){
                int lake = rains[i];
                ans[i] = -1;
                if(mp.count(lake)){
                    auto it = temp.upper_bound(mp[lake]);
                    if(it == temp.end()){
                        return {};
                    }
                    ans[*it] = lake;
                    temp.erase(it);
                }
                mp[lake] = i;
            }
            else{
                temp.insert(i);
            }
        }
        return ans;
    }
};