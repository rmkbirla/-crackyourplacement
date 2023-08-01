/*

The structure of linked list is the following
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

class Solution
{
    public:
    
     Node *zigZag(Node* head)
    {
        Node* ptr;
        ptr = head;
        int i=0;
        while(ptr->next!=nullptr){
            if(i%2==0){
                if(ptr->data>ptr->next->data)
                {   
                    swap(ptr->data,ptr->next->data);
                }
            }
            else{
                if(ptr->data<ptr->next->data)
                {   
                    swap(ptr->data,ptr->next->data);
                }
            }
            i++;
            ptr= ptr->next;
        }
        return head;
    }
};
