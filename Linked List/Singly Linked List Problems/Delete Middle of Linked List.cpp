// Brute Force==> Find mid using length and then proceed

================================================================================================================================

// Optimal Solution==> Use Floyd's cycle detection algorithmto find mid but use extra pointer prev

/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/


// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node* head)
{
    // Your Code Here
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    
    Node* prev=NULL;
    Node* slow=head;
    Node* fast=head;
    
    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    
    Node* temp=slow;
    prev->next=temp->next;
    
    temp->next=NULL;
    delete temp;
    
    return head;
}
