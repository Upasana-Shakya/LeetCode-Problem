class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        ans.push_back({rStart, cStart});
        int n = rows*cols;

        int r = rStart, c = cStart;

        int x = 1;

        while(ans.size() < n){
            if(x % 2 == 1){
                for(int i=0 ; i < x ; i++){
                    int col = c + 1;
                    if(col < cols && col >= 0 && r < rows && r >= 0){
                        ans.push_back({r, col});
                    }
                    c = col;
                }
                for(int i=0 ; i<x ; i++){
                    int row = r + 1;
                    if(row < rows && row >= 0 && c < cols && c >= 0){
                        ans.push_back({row, c});
                    }
                    r = row;
                }
            }
            else{
                for(int i=0 ; i < x ; i++){
                    int col = c - 1;
                    if(col < cols && col >= 0 && r < rows && r >= 0){
                        ans.push_back({r, col});
                    }
                    c = col;
                }
                for(int i=0 ; i<x ; i++){
                    int row = r - 1;
                    if(row < rows && row >= 0 && c < cols && c >= 0){
                        ans.push_back({row, c});
                    }
                    r = row;
                }
            }
            x++;
        }
        return ans;
    }
};