class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int i, int j){
        vector<int>v(10, 0);
        for(int r=0 ; r<3 ; r++){
            for(int c=0 ; c<3 ; c++){
                int num = grid[r+i][c+j];
                if(num < 1 || num > 9){
                    return false;
                }
                v[num]++;
            }
        }
        for(int id=1 ; id<10 ; id++){
            if(v[id] > 1){
                return false;
            }
        }
        int d1 = grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
        int d2 = grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];

        if(d1 != d2){
            return false;
        }

        int s1 = grid[i][j]+grid[i][j+1]+grid[i][j+2];
        int s2 = grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];
        int s3 = grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];

        if(!(s1 == d1 && s2==d1 && s3==d1)){
            return false;
        }

        int s4 = grid[i][j]+grid[i+1][j]+grid[i+2][j];
        int s5 = grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
        int s6 = grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];
        
        if(!(s4 == d1 && s5==d1 && s6==d1)){
            return false;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count=0;

        for(int i=0 ; i<m-2 ; i++){
            for(int j=0 ; j<n-2 ; j++){
                if(isMagicSquare(grid, i, j)){
                    count++;
                }
            }
        }
        return count;
    }
};