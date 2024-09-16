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

            if(totalMinutes == 0){
                mit.push_back(1440);
            }
            else{
                mit.push_back(totalMinutes);
            }
        }

        sort(mit.begin(), mit.end());
        
        for(int i=0 ; i<n-1 ; i++){
            for(int j=i+1 ; j<n ; j++){
                int diff = mit[j]-mit[i];
                res = min(res, diff);
            }
        }
        int lastDiff1 = (mit[0] + 1440)- mit[n-1];
        int lastDiff2 = mit[n-1] - mit[0];
        int lastDiff = min(lastDiff1 , lastDiff2);
        res = min(res, lastDiff);
        return res;
    }
};