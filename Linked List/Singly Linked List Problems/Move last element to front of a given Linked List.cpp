#include <bits/stdc++.h> 
/****************************************************************

Following is the class structure of the Node class:

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
	        this->data = data;
	        this->next = NULL;
        }
    };

*****************************************************************/

Node *delAddLastNode(Node *head){
	// Write your code here.
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* curr=head;

    while(curr->next!=NULL){
        curr=curr->next;
    }

    curr->next=head;
    head=curr;

    curr=curr->next;

    while(curr->next!=head){
        curr=curr->next;
    }

    curr->next=NULL;

    return head;
}
