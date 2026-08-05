class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        vector<bool> suspicious(n, false);

        for (auto it : invocations) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        while (!q.empty()) {
            int ft = q.front();
            q.pop();

            for (auto it : adj[ft]) {
                indegree[it]--;
                if (!suspicious[it]) {
                    suspicious[it] = true;
                    q.push(it);
                }
            }
        }

        vector<int> result;
        bool flag = false;

        for (int i = 0; i < n; i++) {
            if (suspicious[i] && indegree[i] > 0) {
                flag = true;
                break;
            }

            if (!suspicious[i]) {
                result.push_back(i);
            }
        }

        if (flag) {
            vector<int> v;
            for (int i = 0; i < n; i++) {
                v.push_back(i);
            }
            return v;
        }

        return result;
    }
};