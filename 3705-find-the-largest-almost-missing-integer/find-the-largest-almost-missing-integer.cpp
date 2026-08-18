class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> map;
        for(int i=0;i<=n-k;i++){
            unordered_set<int> s;
            for(int j=i;j<i+k;j++){
                s.insert(nums[j]);
            }
            for(int x:s){
                map[x]++;
            }
        }
        int ans=-1;
        for(const auto& [key,value]:map){
            if(value==1 && ans<key){
                ans=key;
            }
        }
        return ans;
    }
};