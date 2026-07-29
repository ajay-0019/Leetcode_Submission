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
    void solve2(int &nums, TreeNode*root){
        if(root==nullptr){
            return;
        }
        solve2(nums,root->left);
        nums=nums-root->val;
        root->val=nums+root->val;
        solve2(nums,root->right);
    }
    void solve(int &nums, TreeNode* root){
        if(root==nullptr){
            return;
        }
        solve(nums,root->left);
        nums+=root->val;
        solve(nums,root->right);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root==nullptr){
            return root;
        }
        int nums=0;
        solve(nums,root);;
        solve2(nums,root);
        return root;
    }
};