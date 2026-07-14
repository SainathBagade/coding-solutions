# Number of Provinces

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

There are `n` cities. Some of them are connected, while some are not. If city `a` is connected directly with city `b`, and city `b` is connected directly with city `c`, then city `a` is connected indirectly with city `c`.

A  **province**  is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an `n x n` matrix `isConnected` where `isConnected[i][j] = 1` if the `ith` city and the `jth` city are directly connected, and `isConnected[i][j] = 0` otherwise.

Return  *the total number of  **provinces***.

 

 **Example 1:** 

```
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

```

 **Example 2:** 

```
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3

```

 

 **Constraints:** 

- 1 <= n <= 200
- n == isConnected.length
- n == isConnected[i].length
- isConnected[i][j] is 1 or 0.
- isConnected[i][i] == 1
- isConnected[i][j] == isConnected[j][i]

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 19.7 MB (beats 54.73%)  
**Submitted:** 2026-07-14T04:10:34.366Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-provinces/)