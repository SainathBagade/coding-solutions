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