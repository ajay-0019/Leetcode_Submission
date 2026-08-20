class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        auto solve=[&](auto &&self, int i, int k)->int{
            if(k==1){
                int ans=accumulate(nums.begin()+i,nums.end(),0);
                return ans;
            }
            if(dp[i][k]!=-1){
                return dp[i][k];
            }
            int ans=INT_MAX;
            int cost=0;
            for(int j=i;j<=n-k;j++){
                cost+=nums[j];
                ans=min(ans,max(cost, self(self, j+1, k-1)));
            }
            return dp[i][k]=ans;
        };
        int ans=solve(solve,0,k);
        return ans;
    }
};