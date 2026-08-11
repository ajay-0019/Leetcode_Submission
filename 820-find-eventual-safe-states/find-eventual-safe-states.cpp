class Solution {
public:
    bool dfs(int node, vector<bool> &visited, vector<bool> &instack,vector<vector<int>> &graph,vector<bool> &incycle){
        visited[node]=true;
        instack[node] = true;
        incycle[node]=true;
        for(int neighbor:graph[node]){
            if(instack[neighbor]){
                return true;
            }
            if(!visited[neighbor] && dfs(neighbor,visited,instack,graph,incycle)){
                return true;
            }
        }
        instack[node] = false;
        incycle[node]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> incycle(n,false);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(incycle[i]){
                continue;
            }
            vector<bool> instack(n);
            instack[i]=true;
            vector<bool> visited(n);
            visited[i]=true;
            dfs(i,visited,instack,graph,incycle);
            if(!incycle[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};