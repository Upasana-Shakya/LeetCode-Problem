class Solution {
public:
    int findMinDifference(vector<string>& t) {
        int n = t.size();
        int res = INT_MAX;
        vector<int> mit;

        for(auto curr : t){
            int hours = stoi(curr.substr(0,2));
            int minutes = stoi(curr.substr(3,2));
            int totalMinutes = hours*60 + minutes;

            mit.push_back(totalMinutes);
        }

        sort(mit.begin(), mit.end());
        
        for(int i=0 ; i<n-1 ; i++){
            int diff = mit[i+1]-mit[i];
            res = min(res, diff);
        }
        int lastDiff1 = (mit[0] + 1440)- mit[n-1];
        int lastDiff2 = mit[n-1] - mit[0];
        int lastDiff = min(lastDiff1 , lastDiff2);
        res = min(res, lastDiff);
        return res;
    }
};