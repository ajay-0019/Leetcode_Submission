class Solution {
public:
    void solve(int i,int j,vector<vector<int>> &grid,long long &sum){
        if(i<0 ||j<0 ||i>=grid.size() ||j>=grid[0].size() || grid[i][j]==0){
            return ;
        }
        sum+=grid[i][j];
        grid[i][j]=0;
        solve(i+1,j,grid,sum);
        solve(i-1,j,grid,sum);
        solve(i,j-1,grid,sum);
        solve(i,j+1,grid,sum);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0){
                    long long  total=0;
                    solve(i,j,grid,total);
                    if(total%k==0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};