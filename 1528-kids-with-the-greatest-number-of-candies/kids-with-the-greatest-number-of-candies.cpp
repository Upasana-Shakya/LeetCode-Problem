class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int maxCandies = *max_element(candies.begin(), candies.end());

        for(auto candy : candies){
            if(candy + extraCandies >= maxCandies){
                res.push_back(true);
            }
            else{
                res.push_back(false);
            }
        }
        return res;
    }
};