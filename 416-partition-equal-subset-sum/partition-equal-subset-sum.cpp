class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1){
            return false;
        }
        int n=nums.size();
        auto solve=[&](auto &&self, vector<vector<int>>& dp, int targetSum,int i)->bool{
            if(targetSum==0){
                return true;
            }
            if(i==n || targetSum<0){
                return false;
            }
            if(dp[i][targetSum]!=-1){
                return dp[i][targetSum];
            }
            bool take=self(self,dp,targetSum-nums[i],i+1);
            bool skip=self(self,dp,targetSum,i+1);
            return dp[i][targetSum]=take||skip;
        };
        int targetSum=sum/2;
        vector<vector<int>> dp(n,vector<int>(targetSum+1,-1));
        bool ans=solve(solve,dp,targetSum,0);
        return ans;
    }
};