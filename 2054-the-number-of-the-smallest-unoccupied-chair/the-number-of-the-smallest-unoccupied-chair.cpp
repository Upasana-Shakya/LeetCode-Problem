class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        vector<pair<int, int>> arrivals;
        for(int i=0 ; i<n ; i++){
            arrivals.push_back({times[i][0], i});
        }

        sort(arrivals.begin(), arrivals.end());

        priority_queue<int, vector<int>, greater<int>> available_chairs;
        for(int i=0 ; i<n ; i++){
            available_chairs.push(i);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leaving_queue;

        for(auto &arrival : arrivals){
            int arrivalTime = arrival.first;
            int friendIndex = arrival.second;

            while(!leaving_queue.empty() && leaving_queue.top().first <= arrivalTime){
                available_chairs.push(leaving_queue.top().second);
                leaving_queue.pop();
            }

            int chair = available_chairs.top();
            available_chairs.pop();

            if(friendIndex == targetFriend){
                return chair;
            }

            leaving_queue.push({times[friendIndex][1], chair});
        }
        return -1;
    }
};