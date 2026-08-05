class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n+1);
        for(auto i:paths){
            int u=i[0];
            int v=i[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]!=-1){
                continue;
            }
            color[i]=1;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto neighbor:graph[node]){
                    if(color[neighbor]==-1){
                        color[neighbor] = max(1, (color[node] + 1) % 5);
                        q.push(neighbor);
                    }else if(color[neighbor] == color[node]) {
                            color[neighbor] = max(1, (color[node] + 1) % 5);
                        }
                }
            }
        }
        vector<int> ans;
        for(int i=1;i<color.size();i++){
            ans.push_back(color[i]);
        }
        return ans;
    }
};