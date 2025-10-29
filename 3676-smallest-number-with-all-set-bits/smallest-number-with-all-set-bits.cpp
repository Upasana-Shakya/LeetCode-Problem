class Solution {
public:
    int smallestNumber(int n) {
        int count=0;

        while(n>0){
            count++;
            n /= 2;
        }

        int res = 0;
        for(int i=0 ; i<count ; i++){
            res += pow(2, i);
        }
        return res;
    }
};