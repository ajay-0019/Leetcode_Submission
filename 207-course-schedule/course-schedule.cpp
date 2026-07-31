class Solution {
public:
    bool dfs(int node, vector<bool> &visited, vector<bool> &instack, vector<vector<int>> &adj){
        visited[node]=true;
        instack[node]=true;
        for(auto n:adj[node]){
            if(!visited[n]){
                if(dfs(n,visited,instack,adj)){
                    return true;
                }
            }else if(instack[n]){
                return true;
            }
        }
        instack[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto i:prerequisites){
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
        }
        vector<bool> visited(numCourses);
        vector<bool> instack(numCourses);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,visited,instack,adj)){
                    return false;
                }
            }
        }
        return true;
    }
};