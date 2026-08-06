class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[nums[i]-1]){
                visited[nums[i]-1]=true;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};