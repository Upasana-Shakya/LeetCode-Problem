class Solution {
public:
    bool isPalindrome(int n) {
        if(n < 0){
            return false;
        }
        long reverse = 0;
        long x = n;
        while(x != 0){
            int digit = x % 10;
            reverse = reverse * 10 + digit;
            x = x / 10;
        }
        if( n == reverse){
            return true;
        }
        else{
            return false;
        }
    }
};