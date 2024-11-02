class Solution {
public:
    bool isCircularSentence(string s) {
        int n = s.size();

        if(s[n-1] != s[0]){
            return false;
        }

        for(int i=0 ; i<n ; i++){
            char ch;
            if(s[i+1] == ' '){
                ch = s[i];
                i += 1;
                if(ch != s[i+1]){
                    return false;
                }
            }
            else{
                continue;
            }
        }
        return true;
    }
};