class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=nums[0];
        if(dp[n]!=-1){
            return dp[n];
        }
        for(int i=2;i<=n;i++){
            dp[i]=max(dp[i-1],nums[i-1]+dp[i-2]);
        }
        return dp[n];
    }
};