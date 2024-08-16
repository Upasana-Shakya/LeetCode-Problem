class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int maxDistance = 0;
        int mini = arrays[0][0];
        int maxi = arrays[0].back();

        for(int i=1 ; i<n ; i++){
            int d1 = abs(maxi - arrays[i][0]);
            int d2 = abs(arrays[i].back() - mini);
            maxDistance = max(maxDistance, max(d1, d2));
            mini = min(mini, arrays[i][0]);
            maxi = max(maxi, arrays[i].back());
        }
        return maxDistance;
    }
};