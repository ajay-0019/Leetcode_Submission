class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size()==1 && k!=nums[0]){
            return 0;
        }
        vector<int> prefix(nums.size()+1);
        prefix[0]=0;
        for(int i=1;i<=nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        int total=0;
        for (int i = 0; i < prefix.size(); i++) {
            for (int j = i + 1; j < prefix.size(); j++) {
                int sum = prefix[j] - prefix[i]; 
                if (sum == k) { 
                    total++; 
                }
            }
            
        }
        return total;
    }
};