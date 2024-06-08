class Solution {
public:
    bool isFascinating(int n) {
        int n1 = 2*n;
        int n2 = 3*n;

        vector<int> hash(10, 0);

        while(n != 0){
            int d = n%10;
            hash[d]++;
            n /= 10;
        }
        while(n1 != 0){
            int d = n1 % 10;
            hash[d]++;
            n1 = n1 / 10;
        }
        while(n2 != 0){
            int d = n2 % 10;
            hash[d]++;
            n2 = n2 / 10;
        }
        if(hash[0] > 0){
            return false;
        }
        for(int i=1 ; i<=9 ; i++){
            if(hash[i] > 1){
                return false;
            }
        }
        return true;
    }
};