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
    ListNode* reverse_list(ListNode* curr){
        ListNode* pre=NULL;
        while(curr!=NULL){
            ListNode* nex=curr->next;
            curr->next=pre;
            pre=curr;
            curr=nex;     
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* dummy=head;

        while(fast->next!=NULL &&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse_list(slow->next);
        slow=slow->next;
        
        while(slow!=NULL){
            if(slow->val!=dummy->val)
                return false;
            slow=slow->next;
            dummy=dummy->next;
        }
        return true;
        
    }
};