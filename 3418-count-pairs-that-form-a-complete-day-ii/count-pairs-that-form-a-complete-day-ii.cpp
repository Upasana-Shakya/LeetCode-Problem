class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long count = 0;
        int n = hours.size();
        vector<int> v(24, 0);

        for(auto h : hours){
            int rem = h % 24;
            int need = (24 - rem) % 24;
            count += v[need];
            v[rem]++;
        }
        return count;
    }
};