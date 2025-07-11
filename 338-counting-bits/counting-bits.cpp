class Solution {
public:
    int countOnes(int i){
        int res = 0;

        while(i){
            if(i % 2 == 1){
                res++;
            }
            i /= 2;
        }
        return res;

    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);

        for(int i=0 ; i<n+1 ; i++){
            ans[i] = countOnes(i);
        }
        return ans;
    }
};