class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int m = word1.size();
        int n = word2.size();

        int p = min(m, n);
        int i=0;
        for( ; i<p ; i++){
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
        }
        if(m-p != 0){
            while(i != m){
                ans.push_back(word1[i]);
                i++;
            }
        }
        if(n-p != 0){
            while(i != n){
                ans.push_back(word2[i]);
                i++;
            }
        }
        return ans;
    }
};