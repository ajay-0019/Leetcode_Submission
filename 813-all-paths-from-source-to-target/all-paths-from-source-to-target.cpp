class Solution {
public: 
    void dfs(int node,int target,vector<bool> &visited, vector<vector<int>> &ans,vector<int> temp,vector<vector<int>>& graph){
        temp.push_back(node);
        if(node==target){
            ans.push_back(temp);
            return;
        }
        visited[node]=true;
        for(auto neighbor:graph[node]){
            if(!visited[neighbor]){
                dfs(neighbor,target,visited,ans,temp,graph);
            }
        }
        visited[node]=false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(n,false);
        dfs(0,n-1,visited,ans,temp,graph);
        return ans;
    }
};