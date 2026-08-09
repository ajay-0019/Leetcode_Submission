class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n=parent.size();
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) {
                graph[i].push_back(parent[i]);
                graph[parent[i]].push_back(i);
            }
        }
        queue<pair<int,int>> q;
        q.push({0,1});
        vector<bool> visited(n);
        int height=1;
        vector<int> depth(n,1);
        visited[0]=true;
        while(!q.empty()){
            auto [node, dpt]=q.front();
            q.pop();
            height=max(height,dpt);
            depth[node]=dpt;
            for(int neighbor: graph[node]){
                if(!visited[neighbor]){
                    visited[neighbor]=true;
                    q.push({neighbor,dpt+1});
                }
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=1LL*nums[i]*(height-depth[i]+1);
        }
        return ans;
    }
};