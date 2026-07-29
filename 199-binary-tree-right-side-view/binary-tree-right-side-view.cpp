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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        vector<int> ans;
        queue<TreeNode*>q;
        q.push(root);
        q.push(nullptr);
        vector<int> temp;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node==nullptr){
                ans.push_back(temp[0]);
                temp.clear();
                if(!q.empty()){
                    q.push(nullptr);
                }
            }else{
                temp.push_back(node->val);
                if(node->right){
                    q.push(node->right);
                }
                if(node->left){
                    q.push(node->left);
                }
            }
        }
        return ans;
    }
};