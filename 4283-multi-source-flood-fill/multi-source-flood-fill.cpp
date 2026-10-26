class Solution {
public:
    void solve(vector<int> &node,vector<vector<int>> &grid,queue<vector<int>> &q){
        if(node[0]>=grid.size() || node[0]<0 || node[1]<0 || node[1]>=grid[0].size() || grid[node[0]][node[1]]!=0){
            return;
        }
        grid[node[0]][node[1]]=node[2];
        q.push({node[0]+1,node[1],node[2]});
        q.push({node[0]-1,node[1],node[2]});
        q.push({node[0],node[1]+1,node[2]});
        q.push({node[0],node[1]-1,node[2]});

    }
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        int total=sources.size();
        vector<vector<int>> grid(n,vector<int>(m,0));
        sort(sources.begin(),sources.end(),[](const auto &a,const auto &b){
            return a[2]>b[2];
        });
        queue<vector<int>> q;
        for(int i=0;i<total;i++){
            q.push(sources[i]);
        }
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            solve(node,grid,q);
        }
        return grid;
    }
};