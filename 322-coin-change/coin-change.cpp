class Solution {
public:
    int coinChange(vector<int>& nums, int amount) {
        int n = nums.size();
        const int INF = 1e9 + 5;
        sort(nums.begin(), nums.end());
        vector<int> cache(amount+1, -1);
        auto recurse = [&](auto&& self, int k)->int{
            if(k==0)
                return 0;
            if(cache[k]!=-1)
                return cache[k];
            int ans = INF;
            for(int i: nums){
                if(i>k) break;
                ans = min(ans, 1 + self(self, k-i));
            }
            return cache[k] = ans;
        };
        int ans = recurse(recurse, amount);
        return (ans>=INF?-1:ans);
    }
};