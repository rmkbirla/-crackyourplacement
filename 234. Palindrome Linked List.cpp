class Solution {
public:
    bool isPalindrome(ListNode* head) {
       ListNode* slow=head;
       ListNode* fast=head;

       while(fast->next!=NULL && fast->next->next!=NULL){
           slow=slow->next;
           fast=fast->next->next;
       }

       ListNode* curr= slow->next;
       ListNode* prev= NULL;
       
       while(curr!=NULL){
           ListNode* temp=curr->next;
           curr->next=prev;
           prev=curr;
           curr=temp;

       }
       
       while(prev!=NULL){
           if(head->val==prev->val){
               head=head->next;
               prev=prev->next;
           }else{
               return false;
           }
       }
       return true;

    }
};
