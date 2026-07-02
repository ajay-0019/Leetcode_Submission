class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int index=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[index]){
                index=i;
            }
        }
        return index;
    }
};