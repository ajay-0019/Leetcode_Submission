class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        vector<bool> visited(arr.size(),false);
        visited[start]=true;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            if((front-arr[front]>=0 && arr[front-arr[front]]==0) || (front+arr[front]<arr.size() && arr[front+arr[front]]==0)){
                return true;
            }else{
                if(front-arr[front]>=0 && visited[front-arr[front]]==false){
                    q.push(front-arr[front]);
                    visited[front-arr[front]]=true;
                } 
                if(front+arr[front]<arr.size() && visited[front+arr[front]]==false){
                    q.push(front+arr[front]);
                    visited[front+arr[front]]=true;
                }
            }
        }
        return false;
    }
};