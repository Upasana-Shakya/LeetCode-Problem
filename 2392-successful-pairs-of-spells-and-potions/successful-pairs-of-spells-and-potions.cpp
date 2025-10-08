class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans(n);

        for(int i=0 ; i<n ; i++){
            int s=0 , e = m-1;
            while(s <= e){
                int mid = s + (e-s)/2;
                if((long long)(spells[i]) * (long long)(potions[mid]) >= success){
                    e = mid-1;
                }
                else{
                    s = mid+1;
                }
            }
            ans[i] = m-s;
        }
        return ans;
    }
};