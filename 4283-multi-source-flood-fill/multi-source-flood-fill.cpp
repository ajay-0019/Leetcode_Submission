class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        int total=sources.size();
        vector<vector<int>> grid(n,vector<int>(m,0));
        sort(sources.begin(),sources.end(),[](const auto &a,const auto &b){
            return a[2]>b[2];
        });
        queue<vector<int>> q;
        for(int i = 0; i < total; i++){
            int r = sources[i][0];
            int c = sources[i][1];
            int color = sources[i][2];
            if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 0) {
                grid[r][c] = color;
                q.push(sources[i]);
            }
        }
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int r=node[0];
            int c=node[1];
            int color=node[2];
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0){
                    grid[nr][nc]=color;
                    q.push({nr,nc,color});
                }
            }
        }
        return grid;
    }
};