class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> p(n, vector<int>(k+1, -1)), curr(n, vector<int>(k+1, -1));

        auto cost = [&](int v){
            return v == 0 ? 0 : 1;
        };
        auto score = [&](int v){
            return v == 0 ? 0 : (v == 1 ? 1 : 2);
        };

        p[0][0] = 0;

        for(int i=0 ; i<m ; i++){
            fill(curr.begin(), curr.end(), vector<int>(k+1, -1));

            for(int j=0 ; j<n ; j++){
                int c = cost(grid[i][j]);
                int s = score(grid[i][j]);

                if(i == 0 && j == 0){
                    curr[0][0] = 0;
                    continue;
                }

                for(int x = 0 ; x <= k-c ; x++){
                    int nc = x+c;
                    int b = -1;
                    if(i > 0 && p[j][x] != -1){
                        b = max(b, p[j][x]+s);
                    }
                    if(j > 0 && curr[j-1][x] != -1){
                        b = max(b, curr[j-1][x]+s);
                    }
                    curr[j][nc] = max(curr[j][nc], b) ;
                }
            }
            p = curr;
        }
        int res = -1;
        for(int c = 0 ; c<=k ; c++){
            res = max(res, p[n-1][c]);
        }
        return res;
    }
};