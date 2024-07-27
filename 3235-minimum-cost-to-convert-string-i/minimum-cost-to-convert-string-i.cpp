class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = 26;

        vector<vector<int>> disc(n,vector<int>(n,INT_MAX));

        for(int i = 0; i<n; i++){
            disc[i][i] = 0;
        }

        for(int i = 0; i<original.size(); i++){
            int from = original[i] - 'a';
            int to = changed[i] - 'a';

            disc[from][to] = min(disc[from][to],cost[i]);
        }

        for(int k = 0; k<n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(disc[i][k] != INT_MAX && disc[k][j] != INT_MAX){
                        disc[i][j] = min(disc[i][j],disc[i][k]+disc[k][j]);
                    }
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i<source.size(); i++){
            if(source[i]!=target[i]){
                int cost = disc[source[i]-'a'][target[i]-'a'];
                if(cost == INT_MAX){
                    return -1;
                } 

                ans += cost;
            }
        }
        return ans;
    }
};