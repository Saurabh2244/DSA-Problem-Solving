// Approach==> We know how to reverse. So reverse upto k then call recursion which will reverse further length-k nodes and 
               finally adjust nodes connection 

============================================================================================================================
===========================================================================================================================

#include <bits/stdc++.h> 
/*********************************************************

    Following is the class structure of the Node class:

    class Node
	{
	public:
	    int data;
	    Node *next;
	    Node *prev;
	    Node(int data)
	    {
	        this->data = data;
	        this->next = NULL;
	        this->prev = NULL;
	    }
	};

************************************************************/
int getLength(Node*&head){
    if(head==NULL) return 0;
    Node* curr=head;
    int cnt=0;

    while(curr!=NULL){
        cnt++;
        curr=curr->next;
    }

    return cnt;
}

Node* solve(Node*&head,int length,int k){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* curr=head;
    Node* Previous=NULL;
    Node* temp=NULL;

    int cnt=0;

    while(curr!=NULL && cnt<k){
        temp=curr->next;
        curr->next=Previous;
        curr->prev=temp;
        Previous=curr;
        curr=temp;

        cnt++;
    }

    if(curr!=NULL){
        head->next=solve(curr,length-k,k);
        if(head->next!=NULL){
            head->next->prev=head;
        }
    }

    Previous->prev=NULL;

    return Previous;
}

Node* reverseDLLInGroups(Node* head, int k)
{	
    // Write your code here. 
    if(head==NULL || head->next==NULL){
        return head;
    }

    int length=getLength(head);
    return solve(head,length,k);
}

