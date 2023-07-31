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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int i=1;
        while(temp->next!=NULL){
            temp=temp->next;
            i++;
        }
        int k=i-n+1;
        if(k==1){
            return head->next;
        }else{
            int j=1;
            ListNode* prev=NULL;
            ListNode* curr=head;
             while(j<k){
                   prev=curr;
                   curr=curr->next;
                   j++;
             }
             prev->next=curr->next;
             delete curr;

            return head;
        }

    }
};
