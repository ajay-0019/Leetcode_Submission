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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        vector<int> vec;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int check=0;
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==nullptr){
                if(check%2==0){
                    ans.push_back(vec);
                }else{
                    reverse(vec.begin(),vec.end());
                    ans.push_back(vec);
                }
                vec.clear();
                if(!q.empty()){
                    q.push(nullptr);
                    check++;
                }
            }else{
                vec.push_back(temp->val);
                if(temp->left!=nullptr ){
                    q.push(temp->left);
                }
                if(temp->right!=nullptr){
                    q.push(temp->right);
                }
            }
        }
        return ans;

    }
};