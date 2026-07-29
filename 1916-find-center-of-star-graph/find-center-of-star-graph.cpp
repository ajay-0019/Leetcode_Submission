#include <algorithm>
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>> adj(n+1);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int center = -1;
        int mx = -1;

        for(int i = 1; i <= n; i++) {
            if((int)adj[i].size() > mx) {
                mx = adj[i].size();
                center = i;
            }
        }

        return center;
    }
};