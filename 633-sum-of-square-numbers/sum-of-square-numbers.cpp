class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a = 0;
        long long b = sqrt(c);

        while(a <= b){
            long long prod = a*a + b*b;
            if(prod == c){
                return true;
            }
            if(prod > c){
                b--;
            }
            else{
                a++;
            }
        }
        return false;
    }
};