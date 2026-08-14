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
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        vector<int> nums;
        ListNode* node=head;
        while(node){
            nums.push_back(node->val);
            node=node->next;
        }
        sort(nums.begin(),nums.end());
        ListNode* ans=new ListNode(nums[0]);
        node=ans;
        for(int i=1;i<nums.size();i++){
            ans->next=new ListNode(nums[i]);
            ans=ans->next;
        }
        return node;
    }
};