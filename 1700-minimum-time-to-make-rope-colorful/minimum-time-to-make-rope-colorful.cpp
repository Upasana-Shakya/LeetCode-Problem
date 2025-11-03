class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int sum = 0;

        for(int i=1 ; i<colors.size() ; i++){
            int maxi = 0;
            while(i < colors.size() && colors[i] == colors[i-1]){
                sum += neededTime[i-1];
                maxi = max(maxi, neededTime[i-1]);
                i++;
            }
            sum += neededTime[i-1];
            maxi = max(maxi, neededTime[i-1]);
            if(maxi != 0){
                sum -= maxi;
            }
        }
        return sum;
    }
};