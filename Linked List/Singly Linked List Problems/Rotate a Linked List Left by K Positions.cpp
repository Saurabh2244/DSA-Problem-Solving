/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        if(head==NULL || k==0){
            return head;
        }
        
        int length=0;
        Node*temp=head;
        while(temp->next!=NULL){
            length++;
            temp=temp->next;
        }
        
        length++;
        
        int jump=k%length;
        
        if(jump==0){
            return head;
        }
        
        temp->next=head;
        temp=head;
        
        while(jump>1){
            temp=temp->next;
            jump--;
        }
        
        head=temp->next;
        temp->next=NULL;
        
        return head;
    }
};
