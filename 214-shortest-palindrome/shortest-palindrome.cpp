class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int i=0;
        
        for(int j = n-1 ; j >= 0 ; j--){
            if(s[i] == s[j]){
                i++;
            }
        }
        if(i == n) return s;

        string subStr = s.substr(i);
        string remain_string = subStr;

        reverse(remain_string.begin() , remain_string.end());

        return remain_string + shortestPalindrome(s.substr(0, i)) + subStr;
    }
};