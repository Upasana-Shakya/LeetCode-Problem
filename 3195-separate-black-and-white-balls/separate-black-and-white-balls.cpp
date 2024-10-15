class Solution {
public:
    long long minimumSteps(string s) {
        int black = 0;
        long long count = 0;

        for(auto ch : s){
            if(ch == '1'){
                black++;
            }
            else{
                count += black;
            }
        }
        return count;
    }
};