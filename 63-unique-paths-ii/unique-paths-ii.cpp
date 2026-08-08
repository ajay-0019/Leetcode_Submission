class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if (grid[0][0] == 1)
            return 0;
        vector<vector<int>> dp(n,vector<int>(m,1));
        bool temp=false;
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                temp=true;
            }
            if(temp){
                dp[i][0]=0;
            }else{
                dp[i][0]=1;
            }
        }
        temp=false;
        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                temp=true;
            }
            if(temp){
                dp[0][i]=0;
            }else{
                dp[0][i]=1;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j]==1){
                    dp[i][j]=0;
                }else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[n-1][m-1];
    }
};