class Solution {
public:
    void solve(vector<string> &ans, int i, string output, string digits, unordered_map<int,string> &mp){
        //Base case
        if(i >= digits.size()){
            ans.push_back(output);
            return;
        }

        int digit = digits[i]-'0';
        string value = mp[digit];
        for(int j=0 ; j<value.size() ; j++){
            char ch = value[j];
            output.push_back(ch);
            solve(ans, i+1, output,digits, mp);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int index = 0;
        string output = "";

        if(digits.empty()){
            return ans;
        }

        unordered_map<int, string> mp = {{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};

        solve(ans, index, output, digits, mp);

        return ans;
    }
};