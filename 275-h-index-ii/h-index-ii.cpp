class Solution {
public:
    int hIndex(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int h = nums[i];
            if (h >= n - i) {
                ans = max(ans,n-i);
            }
        }

        return ans;
    }
};
