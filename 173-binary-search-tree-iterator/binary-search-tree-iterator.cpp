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
class BSTIterator {
public:
    vector<int> nums;
    void solve(TreeNode*root){
        if(root==nullptr){
            return;
        }
        solve(root->left);
        nums.push_back(root->val);
        solve(root->right);
    }
    int i=0;
    BSTIterator(TreeNode* root) {
        solve(root);
    }
    
    int next() {
        return nums[i++];
    }
    
    bool hasNext() {
       return i < nums.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */