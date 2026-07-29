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
    void solve(TreeNode* root,set<int> &nums){
        if(root==nullptr){
            return;
        }
        solve(root->left,nums);
        nums.insert(root->val);
        solve(root->right,nums);
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int> nums;
        solve(root,nums);
        if(nums.size()==1){
            return -1;
        }
        auto it=nums.begin();
        ++it;
        return *it;
    }
};