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
    void solve3(TreeNode* temp){
        if(temp==nullptr){
            return;
        }
        if(temp->left){
            temp->left=nullptr;
        }
        solve3(temp->right);
    }
    void solve2(TreeNode* temp,vector<int>&nums,int i){
        if(temp==nullptr){
            return;
        }
        if(i==nums.size()){
            return;
        }
        if(i<nums.size() && temp->right==nullptr){
            TreeNode* num=new TreeNode(nums[i]);
            temp->right=num;
        }else if(i<nums.size() && temp->right!=nullptr){
            temp->right->val=nums[i];
        }
        solve2(temp->right,nums,i+1);
    }
    void solve(TreeNode* root,vector<int>&nums){
        if(root==nullptr){
            return;
        }
        nums.push_back(root->val);
        solve(root->left,nums);
        solve(root->right,nums);
    }
    void flatten(TreeNode* root) {
        vector<int> nums;
        solve(root,nums);
        TreeNode* temp=root;
        solve2(temp,nums,1);
        temp=root;
        solve3(temp);
    }
};