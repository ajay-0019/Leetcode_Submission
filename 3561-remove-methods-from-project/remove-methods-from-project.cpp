class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        for(auto i:invocations){
            int u=i[0];
            int v=i[1];
            graph[u].push_back(v);

        }
        queue<int> q;
        q.push(k);
        vector<bool> visited(n,false);
        visited[k]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto neighbor:graph[node]){
                if(!visited[neighbor]){
                    visited[neighbor]=true;
                    q.push(neighbor);
                }
            }
        }
        vector<int> ans;
        for(auto& i:invocations){
            int u=i[0];
            int v=i[1];
            if(!visited[u] && visited[v]){
                vector<int> ans;
                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};