class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int ans=0;
        while(right>=left){
            int water=min(height[left],height[right])*(right-left);
            ans=max(ans,water);
            if(height[right]>height[left]){
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
};