int INF=1e9+1;
class Solution {
public:
    int solve(vector<int> &nums, vector<int>&dp, int n){
        if(n==0){
            return 0;
        }
        if(n<0){
            return INF;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int mini=INF;
        for(int i=0;i<nums.size();i++){
            int ans=solve(nums,dp,n-nums[i]);
            if(ans!=INF){
                mini=min(mini,1+ans);
            }
        }
        dp[n]=mini;
        return mini;
    }
    int numSquares(int n) {
        if(n<=1){
            return 1;
        }
        int root=sqrt(n);
        if(root*root==n){
            return 1;
        }
        vector<int> nums;
        for(int i=1;i<=root;i++){
            nums.push_back(i*i);
        }
        vector<int> dp(n+1,-1);
        int ans=solve(nums,dp,n);
        return ans;
    }
};