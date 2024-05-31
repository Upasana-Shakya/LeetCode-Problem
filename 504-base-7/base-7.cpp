class Solution {
public:
    string convertToBase7(int num) {
        string ans = "";
        int temp = abs(num);

        if(num == 0){
            return "0";
        }

        while(temp != 0){
            int d = temp % 7;
            ans = to_string(d) + ans;
            temp = temp/7;
        }
        if(num < 0){
            ans  = "-" + ans;
        }

        return ans;
    }
};