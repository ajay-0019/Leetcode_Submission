class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=cost[0];
        if(dp[n]!=-1){
            return dp[n];
        }
        for(int i=2;i<=n;i++){
            dp[i]=min(dp[i-2]+cost[i-1],dp[i-1]+cost[i-1]);
        }
        return min(dp[n],dp[n-1]);
    }
};