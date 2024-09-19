/*
Structure of the node of the list is as
struct Node
{
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
	}
}; */

Node* getMid(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    Node*slow=head;
    Node*fast=head->next;
    
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    
    return slow;
}

//Function to sort the given doubly linked list using Merge Sort.
Node* merge2DLL(Node *&head1,Node*head2){
    if(head1==NULL){
        return head2;
    }
    
    if(head2==NULL){
        return head1;
    }
    
    if(head1->data <= head2->data){
        head1->next=merge2DLL(head1->next,head2);
        head1->next->prev=head1;
        head1->prev=NULL;
        return head1;
    }
    
    else{
        head2->next=merge2DLL(head1,head2->next);
        head2->next->prev=head2;
        head2->prev=NULL;
        return head2;
    }
}
struct Node *sortDoubly(struct Node *head)
{
	// Your code here
	if(head==NULL || head->next==NULL){
	    return head;
	}
	
	Node* mid=getMid(head);
	Node* head1=head;
	Node* head2=mid->next;
	
	mid->next->prev=NULL;
	mid->next=NULL;
	
	head1=sortDoubly(head1);
	head2=sortDoubly(head2);
	
	return merge2DLL(head1,head2);
}
