class Solution {
public:
int calculateDiameter(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    auto bfs = [&](int start) {
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        int farthestNode = start;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                    if (dist[neighbor] > dist[farthestNode]) {
                        farthestNode = neighbor;
                    }
                }
            }
        }
        return make_pair(farthestNode, dist[farthestNode]);
    };

    int nodeA = bfs(0).first;
    int diameter = bfs(nodeA).second;
    return diameter;
}
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
         int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        int diameter1 = calculateDiameter(n, edges1);
        int diameter2 = calculateDiameter(m, edges2);

        // Minimum diameter after connecting the two trees
        int result = max({diameter1, diameter2, (diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1});
        return result;
    }
};