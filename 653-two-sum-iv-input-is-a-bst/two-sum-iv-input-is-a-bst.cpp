/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, vector<int>&nums){
        if(root==nullptr){
            return;
        }
        solve(root->left,nums);
        nums.push_back(root->val);
        solve(root->right,nums);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        solve(root,nums);
        int i=0,j=nums.size()-1;
        while(j>i){
            if(nums[i]+nums[j]==k){
                return true;
            }
            if(nums[i]+nums[j]>k){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
};