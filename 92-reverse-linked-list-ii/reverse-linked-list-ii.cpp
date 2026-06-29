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
    ListNode* reverse(ListNode* head){
        if(head==nullptr) return nullptr;
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=nullptr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr || head->next==nullptr || left==right) return head;
        int size=1;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev=dummy;
        ListNode* fcurr=head;
        while(size!=left){
            prev=fcurr;
            fcurr=fcurr->next;
            size++;
        }
        ListNode* lcurr=head;
        while(right!=1){
            lcurr=lcurr->next;
            right--;
        }
        ListNode* latt=lcurr->next;
        lcurr->next=nullptr;
        prev->next=nullptr;
        ListNode* temp = reverse(fcurr);
        prev->next=temp;
        fcurr->next=latt;
        return dummy->next;
    }
};