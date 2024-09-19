#include <bits/stdc++.h> 
/****************************************************

    Following is the class structure of the DLLNode class:

    class DLLNode {
    public:
	int data;
	Node *next;

	DLLNode(int data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
}

*****************************************************/

DLLNode* rotateDLL(DLLNode* head, int k) 
{
    // Write your code here.

    if(head==NULL || head->next==NULL){
        return head;
    }
    
    DLLNode* curr=head;
    int length=0;

    while(curr->next!=NULL){
        length++;
        curr=curr->next;
    }
    length++;

    curr->next=head;
    curr=head;

    int jump=k%length;

    if(jump==0){
        return head;
    }


    while(jump>1){
        curr=curr->next;
        jump--;
    }

    DLLNode* temp=curr->next;
    head=temp;

    curr->next=NULL;
    temp->prev=NULL;

    return head;

}
