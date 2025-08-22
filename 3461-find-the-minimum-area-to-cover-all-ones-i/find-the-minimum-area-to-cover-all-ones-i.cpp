class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int top = grid.size();
        int left = grid[0].size();
        int bottom = 0;
        int right = 0;
        
        
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[i].size() ; j++){
                if(grid[i][j] == 1){
                    top = min(top, i);
                    bottom = max(bottom, i);
                    left = min(left, j);
                    right = max(right, j);
                }
            }
        }
        
        int l = bottom - top + 1;
        int w = right - left + 1;
        
        return (l*w);
    }
};