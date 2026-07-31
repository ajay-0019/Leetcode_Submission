class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n+1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && isConnected[i][j]) {
                    adj[i+1].push_back(j+1);
                }
            }
        }
        int ans=0;
        vector<bool> visited(n+1,false);
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                ans++;
                visited[i]=true;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto it:adj[node]){
                        if(!visited[it]){
                            visited[it]=true;
                            q.push(it);
                        }
                    }
                }
            }
        }
        return ans;
    }
};