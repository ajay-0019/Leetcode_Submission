class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1){
            return true;
        }
        if(nums[0]==0){
            return false;
        }
        if(nums.size()==2 && nums[0]!=0){
            return true;
        }
        int n=nums.size();
        vector<bool> dp(n+1,false);
        int last=nums[0];
        for(int i=1;i<n;i++){
            if(last>0){
                dp[i]=true;
                last--;
                last = max(last, nums[i]);
            }else{
                break;
            }
        }
        return dp[n-1];
    }
};