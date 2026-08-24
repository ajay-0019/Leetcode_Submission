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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1 || head==nullptr){
            return head;
        }
        vector<int> nums;
        ListNode* temp=head;
        while(temp){
            nums.push_back(temp->val);
            temp=temp->next;
        }
        int n=nums.size();
        int ignore=n%k;
        for(int i=0;i<n-ignore;i+=k){
            int left=i;
            int right=i+k-1;
            while(left<right){
                swap(nums[left],nums[right]);
                left++;right--;
            }
        }
        ListNode* num = new ListNode(nums[0]);
        ListNode* ans=num;
        for(int i=1;i<n;i++){
            num->next=new ListNode(nums[i]);
            num=num->next;
        }
        return ans;
    }
};