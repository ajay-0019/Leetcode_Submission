class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n==0 || n==1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int total=0;
        for(int i=1;i<=n;i++){
            total+=solve(n-i,dp)*solve(i-1,dp);
        }
        dp[n]=total;
        return total;
    }
    int numTrees(int n) {
        if(n==0 || n==1){
            return 1;
        }
        vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        return solve(n,dp);
    }
};