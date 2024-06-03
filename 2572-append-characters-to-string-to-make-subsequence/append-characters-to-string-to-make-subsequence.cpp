class Solution {
public:
    int appendCharacters(string s, string t) {
        int ch = 0;

        for(auto i : s){
            if(i == t[ch]){
                ch++;
            }
        }
        return t.size()-ch;
    }
};