class Solution {
public:
    int solve(string s){
        string temp = "";

        for(auto ch : s){
            int num = ch - 'a' + 1;
            temp += to_string(num);
        }
        int sum = 0;
        for(auto ch : temp){
            sum += ch - '0';
        }
        return sum;
    }
    int getLucky(string s, int k) {
        int num = solve(s);
        int sum = 0;
        
        if(k == 1){
            return num;
        }
        else{
            k--;
        }
        while(k--){
            int sum = 0;
            while(num){
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};