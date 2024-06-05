class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        int ans = -1;
        unordered_map<char, int> mp;

        for(auto i : s){
            mp[i]++;
        }

        for(int i=0 ; i<n ; i++){
            if(mp[s[i]] == 1){
                ans = i;
                break;
            }
        }
        return ans;
    }
};