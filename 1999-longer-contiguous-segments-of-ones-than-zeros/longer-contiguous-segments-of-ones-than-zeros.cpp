class Solution {
public:
    bool checkZeroOnes(string s) {
        int n = s.size();

        int zeros = 0;
        int max1 = 0;
        int max0 = 0;
        int ones = 0;

        for(auto ch : s){
            if(ch == '1'){
                ones++;
                zeros = 0;
                if(max1 < ones){
                    max1 = ones;
                }
            }
            else{
                zeros++;
                ones = 0;
                if(max0 < zeros){
                    max0 = zeros;
                }
            }
        }
        if(max1 > max0){
            return true;
        }
        return false;
    }
};