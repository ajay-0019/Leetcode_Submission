class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        if(st.size()>=3){
            auto it=next(st.rbegin(),2);
            return *it;
        }
        sort(nums.begin(),nums.end());
        return nums[nums.size()-1];
    }
};