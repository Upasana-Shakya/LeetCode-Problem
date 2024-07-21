class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        int ans = 0;

        for(int i=0 ; i<s.size() ; i++){
            freq[s[i]-'a']++;
        }
        for(int i=0 ; i<26 ; i++){
            if(freq[i] == 0){
                ans += 0;
            }
            else if(freq[i]%2 == 0){
                ans += 2;
            }
            else{
                ans += 1;
            }
        }
        return ans;
    }
};