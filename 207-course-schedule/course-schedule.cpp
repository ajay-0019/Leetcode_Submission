class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto course:prerequisites){
            graph[course[1]].push_back(course[0]);
            indegree[course[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int ans=0;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans++;
            for(auto neighbor:graph[front]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0){
                    q.push(neighbor);
                }
            }
        }
        return ans==numCourses;
    }
};