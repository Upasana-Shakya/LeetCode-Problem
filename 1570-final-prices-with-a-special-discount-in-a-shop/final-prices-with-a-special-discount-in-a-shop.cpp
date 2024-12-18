class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res;
        int n = prices.size();

        for(int i=0 ; i<n-1 ; i++){
            int j=i+1;
            while(prices[j] > prices[i] && j < n-1){
                j++;
            }
            if(j != n && prices[i] >= prices[j]){
                res.push_back(prices[i]-prices[j]);
            }
            else{
                res.push_back(prices[i]);
            }
        }
        res.push_back(prices[n-1]);
        return res;
    }
};