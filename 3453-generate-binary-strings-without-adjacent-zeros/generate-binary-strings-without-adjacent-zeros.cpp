class Solution {
public:
    void generateString(vector<string>& ans, string st, int n){
        if(st.size() == n){
            ans.push_back(st);
            return;
        }

        generateString(ans, st+'1', n);
        if(st.size() == 0 || st.back() == '1'){
            generateString(ans, st+'0', n);
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string st = "";

        generateString(ans, st, n);
        
        return ans;
    }
};