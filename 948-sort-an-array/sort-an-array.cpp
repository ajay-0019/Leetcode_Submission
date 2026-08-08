class Solution {
public:
    void merge(vector<int>&nums, int left, int mid, int right){
        vector<int> leftarray(nums.begin()+left,nums.begin()+mid+1);
        vector<int> rightarray(nums.begin()+mid+1,nums.begin()+right+1);
        int i=0,j=0,k=left;
        while(i<leftarray.size() && j<rightarray.size()){
            if(leftarray[i]>rightarray[j]){
                nums[k++]=rightarray[j++];
            }else{
                nums[k++]=leftarray[i++];
            }
        }
        while(i<leftarray.size()){
            nums[k++]=leftarray[i++];
        }
        while(j<rightarray.size()){
            nums[k++]=rightarray[j++];
        }

    }
    void solve(vector<int>&nums, int left, int right){
        if(left==right){
            return;
        }
        int mid=midpoint(left,right);
        solve(nums,left,mid);
        solve(nums,mid+1,right);
        merge(nums,left,mid,right);
    }
    vector<int> sortArray(vector<int>& nums) {
        solve(nums,0,nums.size()-1);
        return nums;
    }
};