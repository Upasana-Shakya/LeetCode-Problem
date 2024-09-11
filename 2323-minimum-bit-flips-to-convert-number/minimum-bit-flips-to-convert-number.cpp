class Solution {
public:
    string tobinary(int num){
        string res = "";
        while(num){
            res = (num%2 == 0 ? "0" : "1") + res;
            num = num/2;
        }
        return res;

    }
    int minBitFlips(int start, int goal) {
        string s1 = tobinary(start);
        string s2 = tobinary(goal);

        int ans = 0;
        if(s1.size() < s2.size()){
            while(s1.size() != s2.size()){
                s1 = "0" + s1;
            }
        }
        if(s1.size() > s2.size()){
            while(s2.size() != s1.size()){
                s2 = "0" + s2;
            }
        }

        for(int i=0 ; i<s1.size() ; i++){
            if(s1[i] != s2[i]){
                ans++;
            }
        }
        return ans;
    }
};