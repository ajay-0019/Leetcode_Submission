class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int n=nums.size();
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        int num=k;
        while(true){
            if(map.find(num)==map.end()){
                return num;
            }else{
                num+=k;
            }
        }
        return -1;
    }
};