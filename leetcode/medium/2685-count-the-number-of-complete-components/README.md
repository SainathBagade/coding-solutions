# Count the Number of Complete Components

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer `n`. There is an  **undirected**  graph with `n` vertices, numbered from `0` to `n - 1`. You are given a 2D integer array `edges` where `edges[i] = [ai, bi]` denotes that there exists an  **undirected**  edge connecting vertices `ai` and `bi`.

Return  *the number of  **complete connected components**  of the graph*.

A  **connected component**  is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be  **complete**  if there exists an edge between every pair of its vertices.

 

 **Example 1:** 

```
Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
Output: 3
Explanation: From the picture above, one can see that all of the components of this graph are complete.

```

 **Example 2:** 

```
Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
Output: 1
Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.

```

 

 **Constraints:** 

- 1 <= n <= 50
- 0 <= edges.length <= n * (n - 1) / 2
- edges[i].length == 2
- 0 <= ai, bi <= n - 1
- ai != bi
- There are no repeated edges.

## Solution

**Language:** C++  
**Runtime:** 61 ms (beats 37.04%)  
**Memory:** 134.9 MB (beats 44.53%)  
**Submitted:** 2026-07-11T05:11:50.684Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/count-the-number-of-complete-components/)