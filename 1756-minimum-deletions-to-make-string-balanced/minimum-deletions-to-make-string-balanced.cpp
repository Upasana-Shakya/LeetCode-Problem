class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int ans = 0;
        int countb = 0;

        for(auto i : s){
            if(i == 'a'){
                ans = min(ans+1, countb);
            }
            else{
                countb++;
            }
        }
        return ans;
    }
};