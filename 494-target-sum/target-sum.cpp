class Solution {
public:
    void solve(int idx, int currentsum,int target,int &ans,vector<int> &nums){
        if(currentsum==target && idx==nums.size()){
            ans++;
            return;
        }
        if(idx==nums.size()){
            return;
        }
        solve(idx+1,currentsum+nums[idx],target,ans,nums);
        solve(idx+1,currentsum-nums[idx],target,ans,nums);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0;
        int idx=0;
        int currentsum=0;
        solve(idx,currentsum,target,ans,nums);
        return ans;
    }
};