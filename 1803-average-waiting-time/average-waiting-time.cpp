class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        vector<int> waiting_time;
        int end = 0;

        for(int i=0 ; i<n ; i++){
            end = max(end, customers[i][0]);
            end += customers[i][1];
            int ans = end - customers[i][0];
            waiting_time.push_back(ans);
        }

        double res = 0;
        int size = waiting_time.size();
        for(int i=0 ; i<size ; i++){
            res += waiting_time[i];
        }

        return  res/size;

    }
};