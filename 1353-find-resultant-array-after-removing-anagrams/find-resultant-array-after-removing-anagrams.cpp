class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        res.push_back(words[0]);

        for(int i=1 ; i<words.size() ; i++){
            string s1 = words[i], s2 = res.back();
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            if(s1 != s2){
                res.push_back(words[i]);
            }
        }
        return res;
    }
};