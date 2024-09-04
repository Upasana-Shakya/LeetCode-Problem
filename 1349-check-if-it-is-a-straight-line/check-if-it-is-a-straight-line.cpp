class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int n = c.size();
        
        int y2 = c[1][1];
        int y1 = c[0][1];
        int x2 = c[1][0];
        int x1 = c[0][0];
        
        int dx = x2-x1;
        int dy = y2-y1;

        for(int i = 2 ; i<n ; i++){
            int x = c[i][0];
            int y = c[i][1];
            if(dx * (y-y1) != dy * (x-x1)){
                return false;
            }
        }
        return true;
    }
};