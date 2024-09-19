// Brute Force==> Use 2 pointer Approach but push each number in new Linked List. So extra space is used.

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.

void insertAtTail(Node*&head,Node*&tail,int data){
    
    if(head==NULL){
        Node*node1=new Node(data);
        head=node1;
        tail=node1;
    }
        
    else{
        Node*temp=new Node(data);
        tail->next=temp;
        tail=temp;
    }
    
}

Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    if(head1==NULL){
        return head2;
    }
    
    if(head2==NULL){
        return head1;
    }
    
    Node* ansHead=NULL;
    Node* ansTail=NULL;
    
    Node* curr1=head1;
    Node* curr2=head2;
    
    while(curr1!=NULL && curr2!=NULL){
        
        if(curr1->data <= curr2->data){
            insertAtTail(ansHead,ansTail,curr1->data);
            curr1=curr1->next;
        }
        
        else{
            insertAtTail(ansHead,ansTail,curr2->data);
            curr2=curr2->next;
        }
    }
    
    while(curr1!=NULL){
        insertAtTail(ansHead,ansTail,curr1->data);
        curr1=curr1->next;
    }
    
    while(curr2!=NULL){
        insertAtTail(ansHead,ansTail,curr2->data);
        curr2=curr2->next;
    }
    
    return ansHead;
} 

==========================================================================================================================
==========================================================================================================================

// Optimal Solution==> Instead of creating ans List just adjust node. So no extra space required

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.

Node* solve(Node* &head1,Node* &head2){
    Node* curr1=head1;
    Node* next1=curr1->next;
    
    Node* curr2=head2;
    
    while(next1!=NULL && curr2!=NULL){
        
        if(curr1->data <= curr2->data && curr2->data <=next1->data){
            
            Node* next2=curr2->next;
            curr1->next=curr2;
            curr2->next=next1;
            
            curr1=curr2;
            curr2=next2;
        }
        
        else{
            curr1=next1;
            next1=next1->next;
        }
    }
    
    while(curr2!=NULL){
        
        curr1->next=curr2;
        return head1;
    }
    
    return head1;
}

Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    if(head1==NULL){
        return head2;
    }
    
    if(head2==NULL){
        return head1;
    }
    
    if(head1->data > head2->data){
        return sortedMerge(head2,head1);
    }
    
    return solve(head1,head2);
    
} 

===========================================================================================================================
===========================================================================================================================

// Recursive Solution (Super Easy)
/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* h1, Node* h2)  
{  
    // code here
    Node* head1=h1;
    Node* head2=h2;
    
    if(head1==NULL) return head2;
    
    if(head2==NULL) return head1;
    
    if(head1->data<head2->data){
        head1->next=sortedMerge(head1->next,head2);
        return head1;
    }
    
    else{
        head2->next=sortedMerge(head1,head2->next);
        return head2;
    }
}  
