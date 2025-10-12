class Solution {
public:
    static const int MOD = 1'000'000'007;
    int magicalSum(int m, int k, vector<int>& nums) {
        int n = (int)nums.size();
        int B = n + 20;
        vector<int> fact(m + 1, 1), invFact(m + 1, 1);
        for (int i = 1; i <= m; i++)
            fact[i] = 1L * fact[i - 1] * i  % MOD;
        auto modPow = [&](long long a, long long e){
            long long r = 1 % MOD;
            a %= MOD;
            while (e > 0){
                if (e & 1) 
                    r = (r * a) % MOD;
                    a = (a * a) % MOD;
                    e >>= 1;
            }
            return (int)r;
        };
        invFact[m] = modPow(fact[m], MOD - 2);
        for (int i = m; i >= 1; i--)
            invFact[i - 1] = 1LL * invFact[i] * i % MOD;
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));
        dp[0][0][0] = 1;
        for (int i = 0; i < B; i++) {
            vector<vector<vector<int>>> ndp(m + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));

            vector<int> terms(m + 1, 0);
            if (i < n) {
                long long base = (nums[i] % MOD + MOD) % MOD;
                terms[0] = invFact[0];
                for (int t = 1; t <= m; t++) {
                    terms[t] = (int)(1LL * terms[t - 1] * base % MOD);
                }
                for (int t = 0; t <= m; t++) {
                    terms[t] = 1LL * terms[t] * invFact[t] % MOD;
                }
            }

            for (int c = 0; c <= m; c++) {
                for (int s = 0; s <= m; s++) {
                    if (i >= n && s != m) 
                        continue;
                    for (int bits = 0; bits <= k; bits++) {
                        int cur = dp[c][s][bits];
                        if (!cur) 
                            continue;
                        if (i < n) {
                            int max_t = m - s;
                            for (int t = 0; t <= max_t; t++) {
                                int total = c + t;
                                int new_c = total / 2;
                                int new_bit = total % 2;
                                int new_bits = bits + new_bit;
                                if (new_bits > k) continue;
                                ndp[new_c][s + t][new_bits] = (ndp[new_c][s + t][new_bits] + (int)(1LL * cur * terms[t] % MOD)) % MOD;
                            }
                        } else {
                            int total = c;
                            int new_c = total / 2;
                            int new_bit = total % 2;
                            int new_bits = bits + new_bit;
                            if (new_bits <= k) {
                                ndp[new_c][s][new_bits] = (ndp[new_c][s][new_bits] + cur) % MOD;
                            }
                        }
                    }
                }
            }
            dp.swap(ndp);
        }

        long long ans = 0;
        for (int c = 0; c <= m; c++) {
            int popc = __builtin_popcount((unsigned)c);
            for (int bits = 0; bits <= k; bits++) {
                if (popc + bits == k) {
                    ans += dp[c][m][bits];
                    if (ans >= MOD) ans -= MOD;
                }
            }
        }
        ans = ans * fact[m] % MOD;
        return (int)ans;
    }
};