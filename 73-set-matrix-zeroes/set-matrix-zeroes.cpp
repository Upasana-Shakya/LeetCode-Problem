class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> res(m,vector<int>(n));
        res = matrix;

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(matrix[i][j] == 0){
                    for(int p = 0; p<n ; p++){
                        res[i][p] = 0;
                    }
                    for(int p=0 ; p<m ; p++){
                        res[p][j] = 0;
                    }
                }
            }
        }
        matrix = res;
    }
};