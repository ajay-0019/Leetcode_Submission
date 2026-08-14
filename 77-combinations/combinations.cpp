class Solution {
public:
    void solve(vector<int> &nums, int k, vector<vector<int>> &ans,vector<int> &temp,int start){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        for(int i=start;i<nums.size();i++){
            temp.push_back(nums[i]);
            solve(nums,k,ans,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        vector<int> temp;
        solve(nums,k,ans,temp,0);
        return ans;
    }
};