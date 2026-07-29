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
    void solve(TreeNode* root, int&nums){
        if(root==nullptr){
            return ;
        }
        solve(root->right,nums);
        nums+=root->val;
        root->val=nums;
        solve(root->left,nums);
    }
    TreeNode* convertBST(TreeNode* root) {
        int nums=0;
        solve(root,nums);
        return root;
    }
};