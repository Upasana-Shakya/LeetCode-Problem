class Solution {
public:
    vector<vector<int>> generate(int row) {
        if(row == 1){
            return {{1}};
        }
        vector<vector<int>> res(row);

        res[0] = {1};
        res[1] = {1,1};

        for(int i=2 ; i<row ; i++){
            vector<int> v(i+1);
            v[0] = 1;
            v[i] = 1;
            for(int j=1 ; j<i ; j++){
                v[j] = res[i-1][j-1] + res[i-1][j];
            }
            res[i] = v;
        }
        return res;
    }
};