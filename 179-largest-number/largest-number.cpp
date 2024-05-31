class Solution {
public:

    static bool mycomp(string a, string b){
        string x = a+b;
        string y = b+a;
        return x > y;
    }
    string largestNumber(vector<int>& nums) {
        
        vector<string> snums;

        for(auto i : nums){
            snums.push_back(to_string(i));
        }

        sort(snums.begin(), snums.end(), mycomp);

        string ans = "";

        for(auto str : snums){
            ans += str;
        }

        if(ans[0] == '0'){
            return "0";
        }    
        return ans;
    }
};