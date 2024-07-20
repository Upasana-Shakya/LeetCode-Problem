class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>> ans;

        for(int i=0 ; i<m ; i++){
            vector<int> temp;
            for(int j=0 ; j<n ; j++){
                int e = min(rowSum[i], colSum[j]);
                temp.push_back(e);
                rowSum[i] -= e;
                colSum[j] -= e;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};