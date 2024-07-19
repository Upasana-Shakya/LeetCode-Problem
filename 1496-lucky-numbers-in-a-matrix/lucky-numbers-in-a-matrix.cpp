class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rowMin(m);
        vector<int> colMax(n);
        vector<int> ans;

        for(int i=0 ; i<m ; i++){
            int mini = INT_MAX;
            for(int j=0 ; j<n ; j++){
                mini = min(mini, matrix[i][j]);
            }
            rowMin[i] = mini;
        }

        for(int i=0 ; i<n ; i++){
            int maxi = INT_MIN;
            for(int j=0 ; j<m ; j++){
                maxi = max(maxi, matrix[j][i]);
            }
            colMax[i] = maxi;
        }

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]){
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};