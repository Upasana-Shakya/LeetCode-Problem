class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>> ans(m, vector<int>(n));

        for(int i=0 ; i<m ; i++){
            vector<int> temp(n);
            for(int j=0 ; j<n ; j++){
                int e = min(rowSum[i], colSum[j]);
                temp[j] = e;
                rowSum[i] -= e;
                colSum[j] -= e;
            }
            ans[i] = temp;
        }
        return ans;
    }
};