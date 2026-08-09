class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                graph[manager[i]].push_back(i);
            }
        }
        auto dfs=[&](auto &&self,vector<vector<int>>& graph,vector<int> &informTime,int node)->int{
            int maxTime=0;
            for(int v:graph[node]){
                maxTime=max(maxTime,self(self,graph,informTime,v));
            }
            return maxTime+informTime[node];
        };
        return dfs(dfs,graph,informTime,headID);
    }
};