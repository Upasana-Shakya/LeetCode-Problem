class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = 0;

        for(auto i : chalk){
            sum += i;
        }

        k = k % sum;
        
        for(int i=0 ; i<n ; i++){
            if(chalk[i] > k){
                return i;
            }
            k = k - chalk[i];
        }
        return 0;
    }
};