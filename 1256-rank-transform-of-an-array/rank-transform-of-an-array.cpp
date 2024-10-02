class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> map;
        if(arr.size() == 0){
            return {};
        }

        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        int f = 1;
        for(int i=1 ; i<temp.size() ; i++){
            map[temp[i-1]] = f;
            if(temp[i] != temp[i-1]){
                f++;
            }
        }
        map[temp[temp.size()-1]] = f;

        for(int i=0 ; i<arr.size() ; i++){
            arr[i] = map[arr[i]];
        }
        return arr;
    }
};