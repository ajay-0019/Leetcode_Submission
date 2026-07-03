class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> sumLeft(n+1);
        vector<int> sumRight(n+1);
        sumLeft[0]=0;
        sumRight[0]=0;
        for(int i=1;i<=nums.size();i++){
            sumLeft[i]=sumLeft[i-1]+nums[i-1];
            sumRight[i]=sumRight[i-1]+nums[n-i];
        }
        for(int i=1;i<=n;i++){
           if(sumLeft[i-1]-sumLeft[0] == sumLeft[n]-sumLeft[i]){
            return i-1;
           }
        }
        return -1;
    }
};