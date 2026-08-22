class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> map;
        long long ans=0;
        long long sum=0;
        for(int i=0;i<k;i++){
            map[nums[i]]++;
            sum+=nums[i];
        }
        if(map.size()==k){
            ans=sum;
        }
        for(int i=k;i<n;i++){
            map[nums[i]]++;
            sum-=nums[i-k];
            map[nums[i-k]]--;
            sum+=nums[i];
            if(map[nums[i-k]]==0){
                map.erase(nums[i-k]);
            }
            if(map.size()==k){
                ans=max(sum,ans);
            }
        }
        return ans;
    }
};