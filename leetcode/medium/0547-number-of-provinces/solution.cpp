class DisjonintSet {
    vector<int> rank, parent, size;

public:
    DisjonintSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        size.resize(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    void unionByRank(int u, int v) {
        int ult_u = findParent(u);
        int ult_v = findParent(v);
        if (ult_u == ult_v)
            return;

        if (rank[ult_u] < rank[ult_v]) {
            parent[ult_u] = ult_v;
        } else if (rank[ult_v] < rank[ult_u]) {
            parent[ult_v] = ult_u;
        } else {
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ult_u = findParent(u);
        int ult_v = findParent(v);
        if (ult_u == ult_v)
            return;

        if (size[ult_u] < size[ult_v]) {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        } else {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjonintSet ds(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) { 
                if (isConnected[i][j] == 1) {
                    ds.unionBySize(i, j);
                }
            }
        }
        unordered_set<int> st;

        for (int i = 0; i < n; i++) {
            st.insert(ds.findParent(i));
        }

        return st.size();
    }
};