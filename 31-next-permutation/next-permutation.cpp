class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=-1;
        for(int j=nums.size()-1;j>=1;j--){
            if(nums[j]>nums[j-1]){
                i=j-1;
                break;
            }
        }
        if(i==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int j=nums.size()-1;
        while(nums[j]<=nums[i]){
            j--;
        }
        swap(nums[i],nums[j]);
        reverse(nums.begin()+i+1,nums.end());
    }
};