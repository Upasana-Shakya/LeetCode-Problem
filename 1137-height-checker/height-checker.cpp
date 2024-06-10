class Solution {
public:
    int heightChecker(vector<int>& ex) {
        vector<int> h = ex;
        sort(ex.begin(), ex.end());
        int count = 0;

        for(int i=0 ; i<h.size() ; i++){
            if(h[i] != ex[i]){
                count++;
            }
        }
        return count;
    }
};