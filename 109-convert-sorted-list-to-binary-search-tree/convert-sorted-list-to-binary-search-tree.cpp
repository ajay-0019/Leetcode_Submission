/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* buildBST(vector<int>&nums, int left, int right){
        if(left>right){
            return nullptr;
        }
        int mid=right-(right-left)/2;
        TreeNode* temp=new TreeNode(nums[mid]);
        temp->left=buildBST(nums,left,mid-1);
        temp->right=buildBST(nums,mid+1,right);
        return temp;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        ListNode* temp=head;
        while(temp){
            nums.push_back(temp->val);
            temp=temp->next;
        }
        return buildBST(nums,0,nums.size()-1);
    }
};