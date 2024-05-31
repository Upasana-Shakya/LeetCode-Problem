class Solution {
public:
    string largestOddNumber(string num) {
        int idx = 0;
        if(num[num.size()-1] % 2 != 0){
            return num;
        }
        for(int i = num.size()-1 ; i>= 0 ; i--){
            if(num[i] % 2 == 0){
                idx++;
            }
            else{
                break;
            }
        }

        if(idx == num.size()){
            return "";
        }
        num.erase(num.size()-idx);
        return num;
    }
};