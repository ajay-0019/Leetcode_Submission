class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int counter=1;
        int ans=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                counter++;
                ans=max(ans,counter);
            }else{
                counter=1;
            }
        }
        return ans;
    }
};