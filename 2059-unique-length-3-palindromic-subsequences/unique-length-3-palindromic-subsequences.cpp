class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> f(26, n), l(26, -1);

        for(int i=0 ; i<n ; i++){
            int c = s[i] - 'a';
            f[c] = min(f[c], i);
            l[c] = i;
        }

        int res = 0;

        for(int i=0 ; i<26 ; i++){
            int L = f[i], R = l[i];
            if(R-L < 2){
                continue;
            }
            bool seen[26] = {0};

            for(int j=L+1 ; j<R ; j++){
                int idx = s[j] - 'a';
                if(!seen[idx]){
                    seen[idx] = true;
                    res++;
                }
            }
        }
        return res;
    }
};