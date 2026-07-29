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
    void solve(unordered_map<TreeNode* ,pair<int,int>> &mp,TreeNode* root, int l, int r){
        if(!root){
            return;
        }
        solve(mp,root->left,l+1,r-1);
        mp[root].first=l;
        mp[root].second=r;
        solve(mp,root->right,l+1,r+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<TreeNode*,pair<int,int>> mp;
        solve(mp,root,0,0);
        map<int, vector<pair<int,int>>> m;

        for (auto const& [node, counts] : mp) {
            int row = counts.first;
            int col = counts.second;
            m[col].push_back({row, node->val});
        }

        vector<vector<int>> ans;
        for(auto &it:m){
            auto &v=it.second;
            sort(v.begin(),v.end(),[](auto &a, auto &b){
                if(a.first==b.first){
                    return a.second<b.second;
                }
                return a.first<b.first;
            });

            vector<int> temp;
            for(auto &i:v){
                temp.push_back(i.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};