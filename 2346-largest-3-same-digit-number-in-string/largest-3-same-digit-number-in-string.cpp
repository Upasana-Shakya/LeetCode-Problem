class Solution {
public:
    string largestGoodInteger(string num) {
        vector<string> res;

        for(int i=0 ; i<num.size()-2 ; i++){
            if(num[i] == num[i+1] && num[i+1] == num[i+2]){
                string temp = "";
                temp += num[i];
                temp += num[i+1];
                temp += num[i+2];
                res.push_back(temp);
            }
        }
        sort(res.rbegin(), res.rend());
        
        if(res.size() > 0){
            return res[0];
        }
        return "";
    }
};