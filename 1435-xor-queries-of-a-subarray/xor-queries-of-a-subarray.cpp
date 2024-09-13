class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;

        for(auto q : queries){
            int i = q[0];
            int j = q[1];
            int temp = arr[i];
            for(int k = i+1 ; k <= j ; k++){
                temp ^= arr[k];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};