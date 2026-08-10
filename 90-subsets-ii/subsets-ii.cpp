class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        auto solve=[&](auto &&self, int idx)->void{
            ans.push_back(temp);
            for(int i=idx;i<nums.size();i++){
                if (i > idx && nums[i] == nums[i - 1])
                    continue;
                temp.push_back(nums[i]);
                self(self,i+1);
                temp.pop_back();
            }
        };
        solve(solve,0);
        set<vector<int>> s(ans.begin(),ans.end());
        vector<vector<int>> num(s.begin(),s.end());
        return num;
    }
};