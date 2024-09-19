
/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/
class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        //Your code here
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node* curr=head;
        Node* PREV=NULL;
        
        while(curr!=NULL){
            
            Node* temp=curr->next;
            curr->next=PREV;
            curr->prev=temp;
            
            PREV=curr;
            curr=temp;
        }
        
        return PREV;
    }
};
