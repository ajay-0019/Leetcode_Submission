class Solution {
public:
    int robthehouse(vector<int> &nums, int i){
        int maxi=0;
        int premaxi=0;
        if(i==0){
            premaxi = nums[0];
            maxi = max(nums[0], nums[1]);
            for(int i=2;i<nums.size()-1;i++){
                int temp=maxi;
                maxi=max(premaxi+nums[i],maxi);
                premaxi=temp;
            }
            return maxi;
        }else{
            premaxi = nums[1];
            maxi = max(nums[1], nums[2]);   
            for(int i=3;i<nums.size();i++){
                int temp=maxi;
                maxi=max(premaxi+nums[i],maxi);
                premaxi=temp;
            }
        }
        return maxi;
        
    }
    int rob(vector<int>& nums) {
        if(nums.size()==3 || nums.size()==1 || nums.size()==2){
            return *max_element(nums.begin(),nums.end());
        }
        int ans1=robthehouse(nums,0);
        int ans2=robthehouse(nums,1);
        if(ans1>ans2){
            return ans1;
        }
        return ans2;
    }
};