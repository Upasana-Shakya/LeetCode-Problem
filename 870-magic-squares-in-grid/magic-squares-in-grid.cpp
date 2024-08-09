class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int i, int j){
        if(i < grid.size()-1 && j < grid[i].size()-1){
                int r0 = grid[i-1][j-1] + grid[i-1][j] + grid[i-1][j+1];
                int r1 = grid[i][j-1] + grid[i][j] + grid[i][j+1];
                int r2 = grid[i+1][j-1] + grid[i+1][j] + grid[i+1][j+1];

                int c0 = grid[i-1][j-1] + grid[i][j-1] + grid[i+1][j-1];
                int c1 = grid[i-1][j] + grid[i][j] + grid[i+1][j];
                int c2 = grid[i-1][j+1] + grid[i][j+1] + grid[i+1][j+1];

                int d1 = grid[i-1][j-1] + grid[i][j] + grid[i+1][j+1];
                int d2 = grid[i-1][j+1] + grid[i][j] + grid[i+1][j-1];

                int sum = r0;

                if(r0 == sum && r1 == sum && r2 == sum && c0 == sum && c1 == sum && c2 == sum && d1 == sum && d2 == sum ){
                    set<int> s({1,2,3,4,5,6,7,8,9});
                    for(int r = 0 ; r < 3 ; r++){
                        for(int c = 0; c < 3 ; c++){
                            s.erase(grid[i + r - 1][j + c - 1]);
                        }
                    }
                    return s.empty();
                }
        }
        return false;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;

        for(int i=1 ; i<grid.size()-1 ; i++){
            for(int j=1 ; j<grid[0].size()-1 ; j++){
                if(isMagicSquare(grid, i, j)){
                    ans++;
                }
            }
        }
        return ans;
    }
};