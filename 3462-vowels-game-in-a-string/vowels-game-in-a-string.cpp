class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        return false;
    }
    bool doesAliceWin(string s) {
        int count = 0;
        for(auto ch : s){
            if(isVowel(ch)){
                count++;
            }
        }
        if(count == 0){
            return false;
        }
        return true;
    }
};