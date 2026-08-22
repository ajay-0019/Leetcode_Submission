class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> map;
        int balance=0;
        int ans=0;
        map[0]=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                balance--;
            }else{
                balance++;
            }
            if(map.find(balance)!=map.end()){
                ans=max(ans,i-map[balance]);
            }else{
                map[balance]=i;
            }
        }
        return ans;
    }
};