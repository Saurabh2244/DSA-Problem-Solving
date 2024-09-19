//Iterative Solution

/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node* curr=head;
        Node* prev=NULL;
        
        while(curr!=NULL){
            Node* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        
        return prev;
    }
    
};

=============================================================================================================================

//Recursive Solution

/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
    public:
    //Function to reverse a linked list.
    void solve(Node*&head,Node*&curr,Node*&prev){
        
        //base case
        if(curr==NULL){
            head=prev;
            return;
        }
        
        solve(head,curr->next,curr);
        
        curr->next=prev;
    }
    
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node* curr=head;
        Node* prev=NULL;
        
        solve(head,curr,prev);

        return head;
    }
    
};
