class Solution {
public:
    int change(int num){
        int sum=0;
        while(num>0){
            int last=num%10;
            sum+=last;
            num=num/10;
        }
        return sum;
    }
    int differenceOfSum(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>9){
                int c=change(nums[i]);
                sum=sum+nums[i]-c;
            }
        }
        return sum;
    }
};