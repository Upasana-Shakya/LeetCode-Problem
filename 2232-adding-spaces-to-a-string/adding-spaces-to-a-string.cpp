class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string str = "";
        int n = s.size();
        int len = spaces.size();

        int i=0, j=0;
        while(i < len && j < n){
            while(spaces[i] != j && j < n){
                str += s[j];
                j++;
            }
            str += " ";
            i++;
        }
        if(j < n){
            while(j != n){
                str += s[j];
                j++;
            }
        }
        return str;
    }
};