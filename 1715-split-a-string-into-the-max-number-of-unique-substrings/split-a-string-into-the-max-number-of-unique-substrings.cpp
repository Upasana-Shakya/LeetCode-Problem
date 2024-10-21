class Solution {
public:
    int solve(int start, string& s, unordered_set<string>& set){
        if(start == s.size()){
            return 0;
        }
        int maxi = 0;

        for(int i= start+1 ; i <= s.size() ; i++){
            string str = s.substr(start, i - start);
            if(set.find(str) == set.end()){
                set.insert(str);
                maxi = max(maxi, 1 + solve(i, s, set));
                set.erase(str);
            }
        }
        return maxi;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> set;
        return solve(0, s, set);
    }
};