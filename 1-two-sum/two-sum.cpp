class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans(2);
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            int num=target-nums[i];
            if(map.find(num)!=map.end()){
                return {map[num],i};
            }
            map[nums[i]]=i;
        }
        return {};
    }
};