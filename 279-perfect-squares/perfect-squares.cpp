const int INF=1e9;
class Solution {
public:
    int numSquares(int n) {
        if(n==0) return 0;
        vector<int> dp(n+1,-1);
        auto solve=[&](auto &&self, int sum)->int{
            if(sum==0){
                return 0;
            }
            if(sum<0){
                return INF;
            }
            if(dp[sum]!=-1){
                return dp[sum];
            }   
            int ans=INF;
            for(int i=1;i*i<=sum;i++){
                ans=min(ans,1+self(self,sum-i*i));
            }
            return dp[sum]=ans;
        };
        return solve(solve,n);
    }
};