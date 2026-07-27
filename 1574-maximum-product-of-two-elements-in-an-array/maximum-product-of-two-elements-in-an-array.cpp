class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> q;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
        }
        int k=q.top();
        q.pop();
        int l=q.top();
        return (k-1)*(l-1);
    }
};