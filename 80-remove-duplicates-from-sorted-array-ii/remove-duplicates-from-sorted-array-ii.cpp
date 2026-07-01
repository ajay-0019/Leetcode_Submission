class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int diff=nums[0];
        int ans=0;
        int n=nums.size();
        int i=2;
        while(i<nums.size()){
            if(nums[i]==diff && nums[i-1]==diff && nums[i-2]==diff){
                ans++;
                nums.erase(nums.begin()+i);
                i--;
            }else{
                diff=nums[i];
            }
            i++;
        }
        return n-ans;
    }
};