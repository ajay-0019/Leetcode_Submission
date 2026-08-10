class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int sum=0;
        vector<int> dp(target+1,-1);
        sort(nums.begin(),nums.end());
        auto solve=[&](auto &&self, int sum)->int{
            if(sum==target){
                return 1;
            }
            if(sum>target){
                return 0;
            }
            if(dp[sum]!=-1){
                return dp[sum];
            }
            
            int ans=0;
            for(int i=0;i<nums.size();i++){
                ans+=self(self,sum+nums[i]);
            }
            return dp[sum]=ans;
        };
        int ans=solve(solve, 0);
        return ans;
    }
};