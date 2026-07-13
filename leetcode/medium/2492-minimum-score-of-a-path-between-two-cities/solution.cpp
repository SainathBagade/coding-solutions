class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int mini = INT_MAX;
        vector <vector<pair<int, int>>> adj(n + 1);
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int ft = q.front();
            q.pop();
            visited[ft] = true;
            for (auto it : adj[ft]) {
                mini = min(mini, it.second);
               if(!visited[it.first]) q.push(it.first);
            }
        }
        return mini;
    }
};