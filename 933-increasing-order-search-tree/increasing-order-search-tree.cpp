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
    TreeNode* increasingBST(TreeNode* root) {
        if(root==nullptr){
            return root;
        }
        vector<int> nums;
        solve(root,nums);
        TreeNode* head=new TreeNode(nums[0]);
        TreeNode* node=head;
        for(int i=1;i<nums.size();i++){
            TreeNode* temp=new TreeNode(nums[i]);
            node->right=temp;
            node=node->right;
        }
        return head;
    }
};