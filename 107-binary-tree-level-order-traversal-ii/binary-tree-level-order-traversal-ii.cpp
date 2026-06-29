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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        vector<int> preans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==nullptr){
                ans.push_back(preans);
                preans.clear();
                if(q.empty()){
                    break;
                }else{
                    q.push(nullptr);
                }
            }else{
                preans.push_back(curr->val);
                if(curr->left!=nullptr){
                    q.push(curr->left);
                }
                if (curr->right!=nullptr){
                    q.push(curr->right);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};