class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(target<1){
            return 0;
        }
        int prefix=0;
        int total=INT_MAX;
        int i=0;
        for(int j=0;j<nums.size();j++){
            prefix+=nums[j];
            if(prefix<target){
                continue;
            }
            
            while(prefix>=target){
                total=min(total,j-i+1);
                prefix-=nums[i];
                i++;
            }
            if(prefix>=target){
                total=min(total,j-i+1);
            }
        }
        if(total==INT_MAX){
            return 0;
        }
        return total;
    }
};