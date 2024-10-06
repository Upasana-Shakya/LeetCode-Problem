class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> word1, word2;

        int i=0;
        while(i < sentence1.size()){
            string temp = "";
            while(i < sentence1.size() && sentence1[i] != ' '){
                temp += sentence1[i];
                i++;
            }
            word1.push_back(temp);
            i++;
        }
        i=0;
        while(i < sentence2.size()){
            string temp = "";
            while(i < sentence2.size() && sentence2[i] != ' '){
                temp += sentence2[i];
                i++;
            }
            word2.push_back(temp);
            i++;
        }

        i=0;
        int j=0;
        int n1 = word1.size();
        int n2 = word2.size();
        
        while(i < n1 && i < n2 && word1[i] == word2[i]){
            i++;
        }
        while(j < n1-i && j < n2-i && word1[n1-1-j] == word2[n2-1-j]){
            j++;
        }
        if(i+j == n1 || i+j == n2){
            return true;
        }
        return false;
    }
};