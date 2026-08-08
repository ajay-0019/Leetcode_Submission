class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> points(maxi+1,0);
        for(int x:nums){
            points[x]+=x;
        }
        vector<int> dp(points.size()+1,-1);
        dp[0]=0;
        dp[1]=points[0];
        for(int i=2;i<=points.size();i++){
            dp[i]=max(dp[i-1],dp[i-2]+points[i-1]);
        }
        return dp[points.size()];
    }
};