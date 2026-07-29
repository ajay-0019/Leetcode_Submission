class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int frontnode=q.front();
            q.pop();
            for(auto x:rooms[frontnode]){
                if(!visited[x]){
                    visited[x]=true;
                    q.push(x);
                }
            }
        }
        for(auto x:visited){
            if(!x){
                return false;
            }
        }
        return true;
    }
};