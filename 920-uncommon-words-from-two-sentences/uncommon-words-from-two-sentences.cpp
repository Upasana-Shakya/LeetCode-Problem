class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> map;
        vector<string> res;

        string s = s1 + " " + s2;

        string word = "";
        for(auto ch : s){
            if(ch == ' '){
                map[word]++;
                word = "";
            }
            else{
                word += ch;
            }
        }

        if(word != ""){
            map[word]++;
        }

        for(auto mp : map){
            if(mp.second == 1){
                res.push_back(mp.first);
            }
        }
        return res;
    }
};