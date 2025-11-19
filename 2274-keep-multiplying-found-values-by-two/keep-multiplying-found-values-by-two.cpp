class Solution {
public:
    int findFinalValue(vector<int>& nums, int o) {
        map<int, int> mp;

        for(auto num : nums){
            mp[num]++;
        }

        while(mp.find(o) != mp.end()){
            o *= 2;
        }
        return o;
    }
};