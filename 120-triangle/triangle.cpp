class Solution {
public:
    void solve(vector<vector<int>>& triangle, vector<vector<int>> &dp,int i){
        dp[1][0]=dp[0][0]+triangle[1][0];
        dp[1][1]=dp[0][0]+triangle[1][1];
        for(int j=0;j<triangle[i].size();j++){
            if(j==0){
                dp[i][j]=triangle[i][j]+dp[i-1][j];
            }else if(j==i){
                dp[i][j]=triangle[i][j]+dp[i-1][j-1];
            }else{
            dp[i][j]=triangle[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
            }
        }
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==1){
            return triangle[0][0];
        }
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<triangle.size();i++){
            solve(triangle,dp,i);
        }
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            if(dp[n-1][i]<ans){
                ans=dp[n-1][i];
            }
        }
        return ans;
    }
};