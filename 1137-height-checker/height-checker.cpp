class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> h = heights;
        sort(heights.begin(), heights.end());
        vector<int> e = heights;
        int count = 0;

        for(int i=0 ; i<h.size() ; i++){
            if(h[i] != e[i]){
                count++;
            }
        }
        return count;
    }
};