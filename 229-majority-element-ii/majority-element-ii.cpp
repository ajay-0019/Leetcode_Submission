class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int k=n/3;   
        vector<int> ans;
        for(const auto [key,value]:mp){
            if(value>k){
                ans.push_back(key);
            }
        }
        return ans;
    }
};