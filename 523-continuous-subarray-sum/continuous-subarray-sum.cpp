class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int rem=0;
        map[0]=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            rem=sum%k;
            if(map.find(rem)!=map.end() ){
                if(i-map[rem]>=2)
                    return true;
            }else{
                map[rem]=i;
            }
        }
        return false;
    }
};