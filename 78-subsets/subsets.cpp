class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        auto solve=[&](auto &&self, int idx)->void{
            ans.push_back(temp);
            for(int i=idx;i<nums.size();i++){
                temp.push_back(nums[i]);
                self(self,i+1);
                temp.pop_back();
            }
        };
        solve(solve,0);
        return ans;
    }
};