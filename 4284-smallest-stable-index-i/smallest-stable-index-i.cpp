class Solution {
public:
    pair<int,int> solve(vector<int> &nums, int r){
        int n=nums.size();
        int maxi=INT_MIN;
        int mini=INT_MAX; 
        for(int i=0;i<=r;i++){
            maxi=max(maxi,nums[i]);
        }
        for(int i=r;i<n;i++){
            mini=min(mini,nums[i]);
        }
        return {maxi,mini};
    }
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pair<int,int> p=solve(nums,i);
            ans.push_back(p.first-p.second);
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]<=k){
                return i;
            }
        }
        return -1;
    }
};