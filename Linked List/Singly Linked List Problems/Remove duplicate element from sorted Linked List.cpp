// Approach==> Use current pointer and check for its next element is same as current or not.

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
 // your code goes here
 
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    Node* curr=head;
       
    while(curr!=NULL && curr->next!=NULL){
        
        if(curr->data == curr->next->data){
            Node*temp=curr->next;
            
            curr->next=temp->next;
            temp->next=NULL;
            delete temp;
        }
        
        else{
            curr=curr->next;
        }
    }
    
    return head;
    
}
