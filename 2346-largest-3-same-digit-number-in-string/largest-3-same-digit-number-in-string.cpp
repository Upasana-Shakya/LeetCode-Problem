class Solution {
public:
    string largestGoodInteger(string num) {
        bool found = 0;
        int maxi =  INT_MIN;

        for(int i=1 ; i<num.size() ; i++){
            if(num[i-1] == num[i] && num[i] == num[i+1]){
                found = 1;
                int n = num[i];
                maxi = max(maxi,n);
            }
        }

        string ans ="";
        if(found == 0){
            return ans;
        }
        else{
            ans.push_back(maxi);
            ans.push_back(maxi);
            ans.push_back(maxi);
        }
        return ans;
    }
};