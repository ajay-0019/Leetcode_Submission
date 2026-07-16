class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixGcd(n);
        long long ans=0;
        int maxi=nums[0];
        prefixGcd[0]=maxi;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            prefixGcd[i] = __gcd(nums[i], maxi);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        for(int i=0;i<n/2;i++){
            ans+=__gcd(prefixGcd[i],prefixGcd[n-i-1]);
        }
        return ans;
    }
};