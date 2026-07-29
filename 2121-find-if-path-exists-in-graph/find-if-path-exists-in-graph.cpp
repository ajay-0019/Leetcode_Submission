class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination){
            return true;
            
        }
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        q.push(source);
        vector<bool> visited(n,false);
        visited[source]=true;
        while(!q.empty()){
            int frontnode=q.front();
            q.pop();
            for(auto x:adj[frontnode]){
                if(x==destination){
                    return true;
                }
                if(!visited[x]){
                    visited[x]=true;
                    q.push(x);
                }
            }
        }
        return false;
    }
};