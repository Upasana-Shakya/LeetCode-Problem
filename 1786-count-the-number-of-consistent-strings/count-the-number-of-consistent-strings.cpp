class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;

        vector<int> freq(26, 0);

        for(auto ch : allowed){
            freq[ch-'a']++;
        }

        for(auto s : words){
            for(int i=0 ; i<s.size() ; i++){
                if(freq[s[i]-'a'] == 0){
                    break;
                }
                if(i == s.size()-1 && freq[s[i]-'a']>0){
                    count++;
                }
            }
        }
        return count;
    }
};