class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                int num = (i*i)+(j*j);
                int sq = sqrt(num);
                if(sq*sq == num && sq <= n){
                    count++;
                }
            }
        }
        return count;
    }
};