class Solution {
public:
    int climbStairs(int n, vector<int>& cost) {
        if (n == 0) return 0;
        if (n == 1) return cost[0] + 1;
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=cost[0]+1;
        dp[2]=min(dp[1]+cost[1]+1,cost[1]+4);
        for(int j=3;j<=n;j++){
            dp[j]=min(min(dp[j-1]+cost[j-1]+1,dp[j-2]+cost[j-1]+4),dp[j-3]+cost[j-1]+9);
        }
        return dp[n];
    }
};