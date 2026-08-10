class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0;
        auto solve=[&](auto &&self,long long sum,int idx)->void{
            if(idx==nums.size() && sum==target){
                ans++;
                return;
            }
            if(idx==nums.size()){
                return;
            }
            self(self,sum+nums[idx],idx+1);
            self(self,sum-nums[idx],idx+1);
        };
        solve(solve,0,0);
        return ans;
    }
};