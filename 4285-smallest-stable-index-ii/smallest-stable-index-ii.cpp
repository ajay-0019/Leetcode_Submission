class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> maximum(n);
        vector<int> minimum(n);
        maximum[0]=nums[0];
        minimum[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            maximum[i]=max(maximum[i-1],nums[i]);
            minimum[n-i-1]=min(minimum[n-i],nums[n-i-1]);
        }
        for(int i=0;i<n;i++){
            if(maximum[i]-minimum[i]<=k){
                return i;
            }
        }
        return -1;
    }
};