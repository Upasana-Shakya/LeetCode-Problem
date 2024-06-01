class Solution {
public:
    int alternateDigitSum(int n) {
        int rev = 0;

        while(n != 0){
            int d = n % 10;
            rev = rev * 10 + d;
            n = n/10;
        }
        n = rev;
        int sum = 0;
        char ch = '+';

        while(n != 0){
            int d = n % 10;
            if(ch == '+'){
                sum += d;
                ch = '-';
            }
            else{
                sum -= d;
                ch = '+';
            }
            n = n/10;
        }
        return sum;
    }
};