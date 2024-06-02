class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> indices;

        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] == x){
                indices.push_back(i);
            }
        }

        for(int i=0 ; i<queries.size() ; i++){
            if(queries[i] <= indices.size()){
                queries[i] = indices[queries[i]-1];
            }
            else{
                queries[i] = -1;
            }
        }
        return queries;
    }
};