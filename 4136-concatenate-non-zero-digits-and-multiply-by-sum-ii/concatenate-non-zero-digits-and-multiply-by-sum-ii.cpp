class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int mod = 1000000007;
        int m = s.size();
        vector<int> cnt(m+1, 0);
        vector<long long> presum(m+1, 0);
        vector<long long> precon(m+1, 0);
        vector<long long> pow10(m+1, 1);
        for(int i=1 ; i<=m ; i++){
            pow10[i] = (pow10[i-1]*10)%mod;
        }
        for(int i=1 ; i<=m ; i++){
            int d = s[i-1] - '0';
            cnt[i] = cnt[i-1];
            presum[i] = presum[i-1];
            precon[i] = precon[i-1];
            if(d != 0){
                cnt[i] = cnt[i-1]+1;
                presum[i] = presum[i-1]+d;
                precon[i] = (precon[i-1]*10 + d)%mod;
            }
        }
        vector<int> res;
        res.reserve(queries.size());
        for(auto &q : queries){
            int l = q[0], r=q[1];
            int tnz = cnt[r+1]-cnt[l];
            if(tnz == 0){
                res.push_back(0);
                continue;
            }
            long long sumd = presum[r+1] - presum[l];
            long long rightc = precon[r+1];
            long long leftc = precon[l];
            long long x = (rightc - (leftc*pow10[tnz])%mod + mod)%mod;
            long long ans = (x*(sumd%mod))%mod;
            res.push_back((int)ans);
        }
        return res;
    }
};