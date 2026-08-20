class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n,-1);
        auto solve=[&](auto &&self, int i)->int{
            if(i==n){
                return 0;
            }
            int ans=0;
            if(dp[i]!=-1){
                return dp[i];
            }
            int cmax=0;
            for(int j=i;j < min(n, i + k);j++){
                cmax=max(cmax,nums[j]);
                int len=j-i+1;
                int current=cmax*len+self(self,j+1);
                ans=max(ans,current);
            }
            return dp[i]=ans;
        };
        int ans=solve(solve,0);
        return ans;
    }
};