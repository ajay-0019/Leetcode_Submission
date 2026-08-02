class Solution {
public:
    int dfs(int node, vector<vector<int>> &adj,vector<int>&dp,vector<int>&time){
        if(dp[node]!=-1){
            return dp[node];
        }
        int best=0;
        for(auto pre: adj[node]){
            best=max(best,dfs(pre,adj,dp,time));
        }
        return dp[node]=best+time[node-1];
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n+1);
        for(auto pre:relations){
            int u=pre[0];
            int v=pre[1];
            adj[v].push_back(u);
        }
        int ans=0;
        vector<int> dp(n+1,-1);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            ans = max(ans,dfs(i,adj,dp,time));
        }
        return ans;
    }
};