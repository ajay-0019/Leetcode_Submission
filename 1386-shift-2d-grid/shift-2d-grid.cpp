class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        for(int s=0;s<k;s++){
            int temp=grid[n-1][m-1];
            int check=grid[0][0];
            int check1=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    check1=grid[i][j];
                    grid[i][j]=check;
                    check=check1;
                }
            }
            grid[0][0]=temp;
        }
        return grid;
    }
};