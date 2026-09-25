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
using ll=long long;
class Solution {
public: 
    ll treesum(TreeNode* root, unordered_set<ll>& sums){
        if(root==nullptr){
            return 0;
        }
        ll sum = root->val+treesum(root->left, sums)+treesum(root->right, sums);
        sums.insert(sum);
        return sum;
    }

    int maxProduct(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        const int MOD = 1e9 + 7;
        unordered_set<ll> sums;
        ll totalsum=treesum(root, sums);

        ll ans = 0;
        for(ll s: sums){
            ans = max(ans, s*(totalsum-s));
        }
        return ans%MOD;
    }
};