// Floyd's Cycle-Detection Algorithm

/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(head==NULL || head->next==NULL){
            return;
        }
        
        Node*slow=head;
        Node*fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
                break;
            }
        }
        
        if(slow==fast){
            slow=head;
            
            if(slow==fast){
                fast=slow->next;
                
                while(fast->next!=slow){
                    fast=fast->next;
                }
                
                fast->next=NULL;
                return;
            }
            
            else{
                while(slow->next!=fast->next){
                    slow=slow->next;
                    fast=fast->next;
                }
                
                fast->next=NULL;
            }
        }
        
    }
};
