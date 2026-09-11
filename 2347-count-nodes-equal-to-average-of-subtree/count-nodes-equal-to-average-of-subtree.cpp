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
    int sum(TreeNode* root, int &node) {
        if (root == nullptr) {
            return 0;
        }
        node++;
        return root->val + sum(root->left, node) + sum(root->right, node);
    }
    void solve(TreeNode* root,int &ans){
        if(root==nullptr){
            return ;
        }
        int node=0;
        int tsum=sum(root,node);
        if(tsum/node==root->val){
            ans++;
        }
        solve(root->left,ans);
        solve(root->right,ans);
    }
    int averageOfSubtree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int ans=0;
        solve(root,ans);
        return ans;
    }
};