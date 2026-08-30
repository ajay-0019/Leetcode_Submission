class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 1;
        }
        int minIndex = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIndex = max_element(nums.begin(), nums.end()) - nums.begin();
        int l=min(minIndex,maxIndex);
        int r=max(minIndex,maxIndex);
        int left=r+1;
        int right=n-l;
        int both=l+1+n-r;
        return min({left,right,both});
    }
};