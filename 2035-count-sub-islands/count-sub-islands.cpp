class Solution {
public:
    void solve(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, int &flag, int m, int n){
        if(i<0 || j<0 || i >=m || j >= n || grid2[i][j] == 0) return;
        if(grid1[i][j] == 0) flag = 0;
        grid2[i][j] = 0;

        solve(i-1, j, grid1, grid2, flag, m, n);
        solve(i+1, j, grid1, grid2, flag, m, n);
        solve(i, j-1, grid1, grid2, flag, m, n);
        solve(i, j+1, grid1, grid2, flag, m, n);

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int res = 0;

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid2[i][j] == 1){
                    int flag = 1;
                    solve(i, j, grid1, grid2, flag, m, n);
                    res += flag;
                }
            }
        }
        return res;
    }
};