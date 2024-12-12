class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long score = 0;

        while(k--){
            double temp = pq.top();
            pq.pop();
            score += temp;
            pq.push(ceil(temp/3));
        }
        return score;;
    }
};