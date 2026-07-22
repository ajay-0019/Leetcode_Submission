class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if((nums[i]%2==0 && nums[j]%2==1)||(nums[j]%2==0 && nums[i]%2==1)){
                    ans[i]++;
                }
            }
        }
        return ans;
    }
};