# Minimum Spanning Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is provided as a list of edges, where each edge is represented as [u, v, w], indicating an edge between vertex u and vertex v with edge weight w.

```
Input: V = 3, E = 3, Edges = [[0, 1, 5], [1, 2, 3], [0, 2, 1]]
 
Output: 4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.
```

```
Input: V = 2, E = 1, Edges = [[0 1 5]]

 

Output: 5 
Explanation: Only one Spanning Tree is possible which has a weight of 5.

```

**Constraints:
**2 ≤ V ≤ 1000
V-1 ≤ E ≤ (V*(V-1))/2
1 ≤ w ≤ 1000
The graph is connected and doesn't contain self-loops & multiple edges.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-07-14T02:19:29.446Z  

```cpp
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        int sum=0;
        vector<vector<pair<int,int>>>adj(V+1);
        
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<int>visited(V,0);
        
        while(!pq.empty()){
            auto front=pq.top();
            pq.pop();
            int wt=front.first;
            int fNode=front.second;
            if(visited[fNode]==1) continue;
            sum+=wt;
            visited[fNode]=1;
            
            for(auto x:adj[fNode]){
                if(!visited[x.first]){
                    pq.push({x.second,x.first});
                }
            }
        }
    return sum;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1)