class Solution {
public:
    int totalMoney(int n) {
        int m = 1;
        int sum = 0;

        while(n > 0){
            for(int d=0 ; d<min(n, 7); d++){
                sum += m+d;
            }
            n -= 7;
            m++;
        }
        return sum;
    }
};