class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& nums) {
        int n=nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                if(nums[i][1]>=nums[j][0]){
                    ans++;
                }
            }
        }
        return ans;
    }
};