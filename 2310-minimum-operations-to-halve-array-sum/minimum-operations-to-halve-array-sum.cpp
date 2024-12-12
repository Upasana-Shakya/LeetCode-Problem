class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq(nums.begin(), nums.end());

        double long totalSum = 0;
        for(int num : nums){
            totalSum += num;
        }
        double long temp = totalSum;
        int count = 0;

        while(true){
            double sum = pq.top();
            pq.pop();
            pq.push(sum/2);
            count++;
            temp -= (sum - sum/2);
            if(temp <= totalSum/2){
                break;
            }
        }
        return count;
    }
};