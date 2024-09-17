class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> mp1;
        unordered_map<string, int> mp2;
        int count = 0;

        for(auto word : words1){
            mp1[word]++;
        }
        for(auto word : words2){
            mp2[word]++;
        }

        for(auto word : words1){
            if(mp2.find(word) != mp2.end() && mp1[word] == 1 && mp2[word] == 1){
                count++;
            }
        }
        return count;
    }
};