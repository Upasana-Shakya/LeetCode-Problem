class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> ans(2, vector<int>(n, 0));

        int sum = 0;
        for(int i=0 ; i<n ; i++){
            sum += colsum[i];
        }
        if(upper+lower != sum){
            return {};
        }

        for(int i=0 ; i<n ; i++){
            if(colsum[i] == 2){
                ans[0][i] = 1;
                ans[1][i] = 1;
                upper--;
                lower--;
                colsum[i] = 0;
            }
        }
        // Upper------>
        for(int i=0 ; i<n ; i++){
            if(upper && colsum[i]){
                ans[0][i] = 1;
                upper--;
                colsum[i]--;
            }
        }
        // Lower----->
        for(int i=0 ; i<n ; i++){
            if(lower && colsum[i]){
                ans[1][i] = 1;
                lower--;
                colsum[i]--;
            }
        }
        if(lower || upper){
            return {};
        }
        return ans;
    }
};