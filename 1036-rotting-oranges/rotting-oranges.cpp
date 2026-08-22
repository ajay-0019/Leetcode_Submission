class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if (grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        int minute=0;
        vector<pair<int,int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty() && fresh>0){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto p=q.front();
                q.pop();
                for(auto v:dir){
                    int ni=p.first+v.first;
                    int nj=p.second+v.second;
                    if(ni>=0 && ni<n&& nj>=0 && nj<m && grid[ni][nj]==1){
                        grid[ni][nj]=2;
                        fresh--;
                        q.push({ni,nj});
                    }
                }
            }
            minute++;
        }
        if(fresh>0){
            return -1;
        }
        return minute;
    }
};