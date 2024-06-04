class Solution {
public:
    int reverse(int n){
        int ans = 0;

        while(n != 0){
            int d = n%10;
            ans = ans * 10 + d;
            n = n/10;
        }
        return ans;
    }
    bool isSameAfterReversals(int num) {
        int reversed1 = reverse(num);
        int reversed2 = reverse(reversed1);

        if(reversed2 == num){
            return true;
        }
        return false;
    }
};