class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int preans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                ans++;
                preans=max(ans,preans);
            }else{
                ans=0;
            }
        }
        return preans;
    }
};