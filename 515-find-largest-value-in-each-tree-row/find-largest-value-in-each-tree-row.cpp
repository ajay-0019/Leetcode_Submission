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
    vector<int> largestValues(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        vector<int> ans;
        int maxi=INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            TreeNode* frontnode=q.front();
            q.pop();
            if(frontnode!=nullptr && frontnode->val>maxi){
                maxi=frontnode->val;
            }
            if(frontnode==nullptr){
                ans.push_back(maxi);
                maxi=INT_MIN;
                if(!q.empty()){
                    q.push(nullptr);
                }
            }else{
                if(frontnode->left!=nullptr){
                    q.push(frontnode->left);
                }
                if(frontnode->right!=nullptr){
                    q.push(frontnode->right);
                }
            }
        }
        return ans;
    }
};