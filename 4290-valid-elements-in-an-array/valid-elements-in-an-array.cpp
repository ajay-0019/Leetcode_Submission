class Solution {
public:
    bool rcheck(vector<int> &nums, int i){
        if(i==nums.size()-1){
            return true;
        }
        for(int k=i+1;k<nums.size();k++){
            if(nums[i]<=nums[k]){
                return false;
            }
        }
        return true;
    }
    bool lcheck(vector<int> &nums, int i){
        if(i==0){
            return true;
        }
        for(int k=0;k<i;k++){
            if(nums[i]<=nums[k]){
                return false;
            }
        }
        return true;
    }
    vector<int> findValidElements(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(lcheck(nums,i) || rcheck(nums,i)){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};