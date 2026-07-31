class Solution {
public:
    int intersect(const unordered_set<int>& a, const unordered_set<int>& b) {
        int cnt = 0;

        if (a.size() > b.size()) {
            return intersect(b, a); // need an overload
        }

        for (int x : a) {
            if (b.count(x))
                cnt++;
        }

        return cnt;
    }
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        map<int,vector<int>> adj;
        int n=properties.size();
        vector<unordered_set<int>> set(n);
        for(int i=0;i<n;i++){
            set[i] = unordered_set<int>(properties[i].begin(), properties[i].end());
            for(int j=i+1;j<n;j++){
                if(i==j){
                    continue;
                }
                if(intersect(set[i],unordered_set<int>(properties[j].begin(), properties[j].end()))>=k){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n,false);
        queue<int> q;
        int ans=0;
        for(int i=0;i<n;i++){
            if(visited[i]){
                continue;
            }
            ans++;
            q.push(i);
            visited[i]=true;
            while(!q.empty()){
                int frontnode=q.front();
                q.pop();
                for(int iter:adj[frontnode]){
                    if(!visited[iter]){
                        visited[iter]=true;
                        q.push(iter);
                    }
                }
            }
        }
        return ans;
    }
};