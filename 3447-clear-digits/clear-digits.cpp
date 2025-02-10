class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        int i=0;

        while(i < n){
            if(isdigit(s[i])){
                s.erase(s.begin() + i);
                if(i > 0){
                    s.erase(s.begin() + i - 1);
                }
                if(i > 1){
                    i = i-2;
                }
            }
            else{
                i++;
            }
        }
        return s;
    }
};