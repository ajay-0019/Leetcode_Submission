class Solution {
public:
    int robthehouse(vector<int> &nums, int i){
        vector<int> dp(nums.size());
        if(i==0){
            dp[0]=nums[0];
            dp[1]=max(nums[0],nums[1]);
            for(int i=2;i<nums.size()-1;i++){
                dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
            }
            return dp[nums.size() - 2];
        }else{
            dp[1] = nums[1];
            dp[2] = max(nums[1], nums[2]);
            for(int i=3;i<nums.size();i++){
                dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
            }
        }
        return dp[nums.size()-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==3 || nums.size()==1 || nums.size()==2){
            return *max_element(nums.begin(),nums.end());
        }
        int ans1=robthehouse(nums,0);
        int ans2=robthehouse(nums,1);
        return max(ans1,ans2);
    }
};