class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        while(k--){
            int idx;
            int maxi = INT_MIN;
            for(int i=0 ; i<gifts.size() ; i++){
                if(maxi < gifts[i]){
                    maxi = gifts[i];
                    idx = i;
                }
            }
            gifts[idx] = sqrt(maxi);
        }
        long long sum = 0;
        for(auto gift : gifts){
            sum += gift;
        }
        return sum;
    }
};