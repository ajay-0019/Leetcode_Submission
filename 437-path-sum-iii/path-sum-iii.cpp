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
    void solve2(TreeNode* root, long long targetSum, long long &ans){
    if(root==nullptr) return;

    targetSum -= root->val;

    if(targetSum == 0)
        ans++;

    solve2(root->left, targetSum, ans);
    solve2(root->right, targetSum, ans);
}
    void solve(TreeNode* root, long long targetSum, long long& ans){
        if(root==nullptr){
            return;
        }
        solve2(root,targetSum,ans);
        solve(root->left,targetSum,ans);
        solve(root->right,targetSum,ans);
    }
    int pathSum(TreeNode* root, int targetSum) {
        long long ans=0;
        solve(root,targetSum,ans);
        return ans;
    }
};