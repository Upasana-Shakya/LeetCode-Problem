class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &v, int k, int index){
        //Base Case
        if(target == 0 && v.size() == k){
            ans.push_back(v);
            return;
        }
        if(target == 0 && v.size() != k){
            return;
        }
        if(target < 0){
            return;
        }

        for(int i=index ; i<candidates.size() ; i++){
            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }
            v.push_back(candidates[i]);
            solve(candidates, target-candidates[i], ans, v, k, i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates = {1,2,3,4,5,6,7,8,9};
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;

        solve(candidates, n, ans, v, k, 0);

        return ans;
    }
};