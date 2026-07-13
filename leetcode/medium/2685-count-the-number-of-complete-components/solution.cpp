class Solution {
    void dfs(int i, vector<bool>& visited,
             vector<vector<int>>& adj,int& node,int& edge) {
        visited[i] = true;
        node++;
        for (auto it : adj[i]) {
            edge++;
            if (!visited[it]) {
                dfs(it, visited,adj,node,edge);
            }
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int result = 0;
        vector<bool> visited(n, false);
        vector<vector<int>>adj(n);

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int node=0,edge=0;
                dfs(i, visited,adj,node,edge);
                edge/=2;
                if (edge == node * (node - 1) / 2)
                    result++;
               
            }
        }
        return result;
    }
};