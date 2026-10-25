class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination){
            return true;
        }
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        vector<bool> visited(n);
        q.push(source);
        visited[source]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int neighbor:adj[node]){
                if(neighbor==destination){
                    return true;
                }
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor]=true;
                }
            }
        }
        return false;
    }
};