class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,int &node){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;

        if (grid[i][j] == 0)
            return;
        node++;
        grid[i][j]=0;
        dfs(i+1,j,grid,node);
        dfs(i-1,j,grid,node);
        dfs(i,j+1,grid,node);
        dfs(i,j-1,grid,node);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int node=0;
                    dfs(i,j,grid,node);
                    maxi=max(maxi,node);
                }
            }
        }
        return maxi;
    }
};