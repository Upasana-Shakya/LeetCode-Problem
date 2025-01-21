class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long fir_row_sum = 0;
        for(int i=0 ; i<grid[0].size(); i++){
            fir_row_sum += grid[0][i];
        }

        long long sec_row_sum = 0;
        long long min_sum = LONG_LONG_MAX;
        for(int i=0 ; i<grid[0].size() ; i++){
            fir_row_sum -= grid[0][i];
            min_sum = min(min_sum, max(fir_row_sum, sec_row_sum));
            sec_row_sum += grid[1][i];
        }
        return min_sum;
    }
};