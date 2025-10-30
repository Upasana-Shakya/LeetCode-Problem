class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int sum = target[0];

        for(int i=1 ; i<n ; i++){
            int d = target[i]-target[i-1];
            if(d > 0){
                sum += d;
            }
        }
        return sum;
    }
};