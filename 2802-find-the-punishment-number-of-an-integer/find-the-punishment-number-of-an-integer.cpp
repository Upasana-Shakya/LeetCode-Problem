class Solution {
public: 
    bool canPart(int n, int target){
        if(n < target || target < 0){
            return false;
        }
        if(n == target){
            return true;
        }
        return (canPart(n/10, target-(n%10)) || canPart(n/100, target-(n%100)) || canPart(n/1000, target-(n%1000)));
    }
    int punishmentNumber(int n) {
        int sum = 0;

        for(int i = 1 ; i <= n ; i++){
            int sq = i*i;
            if(canPart(sq, i)){
                sum += sq;
            }
        }
        return sum;
    }
};