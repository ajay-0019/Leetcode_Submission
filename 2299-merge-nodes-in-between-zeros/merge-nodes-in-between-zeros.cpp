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
    ListNode* mergeNodes(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }
        vector<int> nums;
        ListNode* node=head;
        int sum=0;
        while(node){
            if(node->val==0 && sum!=0){
                nums.push_back(sum);
                sum=0;
            }else{
                sum+=node->val;
            }
            node=node->next;
        }
        if (nums.empty()) return nullptr;
        ListNode* newhead=new ListNode(nums[0]);
        ListNode* prev=newhead;
        for(int i=1;i<nums.size();i++){
            prev->next=new ListNode(nums[i]);
            prev=prev->next;
        }
        return newhead;
    }
};