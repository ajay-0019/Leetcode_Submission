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
    void solve(vector<vector<int>>&ans, TreeNode* root, int target,vector<int> &temp){
        if(root==nullptr){
            return;
        }
        temp.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr){
            if(root->val==target){
                ans.push_back(temp);
            }
        }else{
            solve(ans,root->left,target-root->val,temp);
            solve(ans,root->right,target-root->val,temp);
        }
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;

        solve(ans,root,targetSum,path);

        return ans;
    }
};