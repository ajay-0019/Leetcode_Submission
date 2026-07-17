class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;
        int ans=INT_MIN;
        while(j<nums.size()){
            ans=max(ans,abs(nums[i]-nums[j]));
            i++;
            j++;
        }
        return ans;
    }
};