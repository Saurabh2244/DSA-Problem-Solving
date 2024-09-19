// Approach==> We know the reverse of LL. So reverse ll upto k. then call recursion and adjust nodes coneection 

==================================================================================================================================
==================================================================================================================================

/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    
    int getLength(node* &head){
        int cnt=0;
        node* temp=head;
        
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        
        return cnt;
    }
    
    node* solve(node* &head,int length,int k){
        //base case
        if(length==0){
            return head;
        }
        
        int cnt=0;
        node* curr=head;
        node* prev=nullptr;
        
        while(curr!=NULL && cnt<k){
            node* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            
            cnt++;
        }
        
        if(curr!=nullptr){
            head->next=solve(curr,length-k,k);
        }
        
        return prev;
    }
    
    struct node *reverseIt (struct node *head, int k)
    { 
        // Complete this method
        int length=getLength(head);
        
        return solve(head,length,k);
    }
};
