class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string str = "";
        int n = s.size();
        int len = spaces.size();
        int j=0;

        for(int i=0 ; i<n ; i++){
            if(j < len && i == spaces[j]){
                str += " ";
                j++;
            }
            str += s[i];
        }
        return str;
    }
};