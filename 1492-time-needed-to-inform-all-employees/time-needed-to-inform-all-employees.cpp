class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                graph[i].push_back(manager[i]);
                graph[manager[i]].push_back(i);
            }
        }
        vector<int>  dp(n);
        auto dfs=[&](auto &&self, vector<vector<int>> &graph,vector<int>& dp, vector<int>& informTime,int node,int parent)->int{
            for(int v:graph[node]){
                if(v==parent){
                    continue;
                }
                self(self,graph,dp,informTime,v,node);
                dp[node]=max(dp[node],dp[v]+informTime[node]);
            }
            return dp[node];
        };
        int ans=dfs(dfs,graph,dp,informTime,headID,-1);
        return ans;
    }
};