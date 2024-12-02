class Solution {
public:
    int isPrefixOfWord(string s, string searchWord) {
        int n = s.size();

        string str = "";
        int i=0;
        int count = 0;

        while(i < n){
            str += s[i];
            if(str == searchWord){
                return count+1;
            }
            if(s[i] == ' '){
                count++;
                str = "";
            }
            i++;
        }
        return -1;
    }
};