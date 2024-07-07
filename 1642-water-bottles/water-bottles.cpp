class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while(numBottles >= numExchange){
            int rem = numBottles % numExchange;
            int newFullBottles = numBottles / numExchange;
            ans += newFullBottles;
            numBottles  = newFullBottles + rem;
        }
        return ans;
    }
};