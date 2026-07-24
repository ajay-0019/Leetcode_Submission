class Solution {
public:
    int solve(int amount,vector<int>& coins, vector<int>& dp){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans=solve(amount-coins[i],coins,dp);
            if(ans!=INT_MAX){
                mini=min(mini,1+ans);
            }
        }
        dp[amount]=mini;
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        dp[0]=0;
        int ans=solve(amount,coins,dp);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};