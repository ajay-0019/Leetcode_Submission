class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> ans(nums.begin(),nums.end());
        if(ans.size()==nums.size()){
            return false;
        }
        return true;
    }
};