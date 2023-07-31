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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp=head;
        ListNode* prev=nullptr;
        ListNode* pfln=NULL;
      ListNode* fln=NULL;
        while(temp!=NULL){
           if(temp->val<x && fln==NULL ){
               prev=temp;
               temp=temp->next;
               continue;
           }
           if(temp->val<x && fln!=NULL){
                ListNode* tt=temp;
                prev->next=temp->next;
                temp=prev->next;
                if(pfln==NULL){
                    tt->next=fln;
                    head=tt;
                }else{
                pfln->next=tt;
                }
                tt->next=fln;
                pfln=tt;
                continue;
           }
           if(temp->val>=x && fln==NULL){
               fln=temp;
               pfln=prev;
           }
           prev=temp;
           temp=temp->next;
           

        }
        return head;
    }
};
