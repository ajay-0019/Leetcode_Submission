class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int sum=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0){
                sum++;
            }
        }
        if(sum==nums1.size() || sum==0){
            return true;
        }
        // if(sum%2==0){
        //     return false;
        // }
        return true;
    }
};