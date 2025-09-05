class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int n = 1;

        while(true){
            long long x = num1 - (long long)(num2)*n;
            if(x < n){
                return -1;
            }
            if( n >= __builtin_popcountll(x)){
                return n;
            }
            n++;
        }
    }
};