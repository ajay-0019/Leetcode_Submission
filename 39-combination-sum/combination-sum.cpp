class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        auto solve=[&](auto &&self,int sum,int start)->void{
            if(sum==target){
                ans.push_back(temp);
                return;
            }
            if(sum>target){
                return;
            }
            for(int i=start;i<nums.size();i++){
                temp.push_back(nums[i]);
                self(self,sum+nums[i],i);
                temp.pop_back();
            }
        };
        solve(solve,0,0);
        return ans;
    }
};