class Solution {
public:
    const int INF=1e9;
    int coinChange(vector<int>& nums, int amount) {
        if(amount==0){
            return 0;
        }
        vector<int> dp(amount+1,-1);
        auto solve=[&](auto && self, vector<int>& dp, int amount, vector<int>& nums)->int{
            if(amount==0){
                return 0;
            }
            if(amount<0){
                return INF;
            }
            if(dp[amount]!=-1){
                return dp[amount];
            }
            int mini=INF;
            for(int i=0;i<nums.size();i++){
                mini=min(mini,self(self,dp,amount-nums[i],nums)+1);
            }
            return dp[amount]=mini;
        };
        int ans=solve(solve,dp,amount,nums);
        return (ans!=INF)?ans:-1;
    }
};