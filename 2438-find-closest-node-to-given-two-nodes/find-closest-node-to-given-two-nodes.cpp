class Solution {
public:
    const int INF=1e9;
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
                graph[i].push_back(edges[i]);
            }
        }
        auto bfs = [&](auto &&self, int node, vector<int>& dist) -> void {
            queue<int> q;

            q.push(node);
            dist[node] = 0;

            while (!q.empty()) {
                int frontnode = q.front();
                q.pop();

                for (int neighbor : graph[frontnode]) {
                    if (dist[neighbor] == -1) {
                        dist[neighbor] = dist[frontnode] + 1;
                        q.push(neighbor);
                    }
                }
            }
        };

        vector<int> dist1(n, -1);
        bfs(bfs, node1, dist1);
        vector<int> dist2(n, -1);
        bfs(bfs, node2, dist2);
        int minDist = INT_MAX;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);

                if (maxDist < minDist) {
                    minDist = maxDist;
                    ans = i;
                }
            }
        }        
        return ans;
    }
};