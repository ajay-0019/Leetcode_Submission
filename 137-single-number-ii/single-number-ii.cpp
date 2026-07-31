class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto [key,value]:mp){
            if(value==1){
                return key;
            }
        }
        return -1;
    }
};