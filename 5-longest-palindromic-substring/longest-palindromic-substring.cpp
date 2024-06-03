class Solution {
public:
    bool isPalindrome(string &s , int i, int j){

        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans = "";

        for(int i=0 ; i<s.size() ; i++){
            for(int j=i ; j<s.size() ; j++){
                if(isPalindrome(s, i, j)){
                    string temp = s.substr(i, j-i+1);  // s.substr(starting index, substring length);
                    if(temp.size() > ans.size()){
                        ans = temp;
                    }
                }
            }
        }
        return ans;
    }
};