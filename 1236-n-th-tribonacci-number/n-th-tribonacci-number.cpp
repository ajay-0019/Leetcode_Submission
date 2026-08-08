class Solution {
public:
    int tribonacci(int n) {
        if (n <= 2) {
            return n == 0 ? 0 : 1;
        }
        vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        auto solve=[&](auto&& self,auto&dp, auto n)->int{
            if(n<=2){
                return dp[n];
            }
            if(dp[n]!=-1){
                return dp[n];
            }
            return dp[n]=self(self,dp,n-1)+self(self,dp,n-2)+self(self,dp,n-3);
        };
        return solve(solve,dp,n);
    }
};