// Problem is same as Leaders in array
===============================================================================================================================

// Brute Force==> Just use 2 loop and check

/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    
    void insertAtTail(Node*&head,Node*&tail,int data){
        
        if(head==NULL){
            Node*temp=new Node(data);
            head=temp;
            tail=temp;
            return;
        }
        
        Node*temp=new Node(data);
        tail->next=temp;
        tail=temp;
    }
    
    Node *compute(Node *head)
    {
        // your code goes here
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node*curr=head;
        
        Node*ansHead=NULL;
        Node*ansTail=NULL;
        
        while(curr!=NULL){
            Node*runner=curr->next;
            bool flag=true;
            while(runner!=NULL){
                if(runner->data>curr->data){
                    flag=false;
                }
                
                runner=runner->next;
            }
            
            if(flag==true){
                insertAtTail(ansHead,ansTail,curr->data);
            }
            
            curr=curr->next;
        }
        
        return ansHead;
    }
    
};
===========================================================================================================================

Optimal Soln==> Reverse linked list and use maxi variable. If any node data is less than maxi then remove that node

/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    
    Node*rev(Node* &head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node*curr=head;
        Node*prev=NULL;
        
        while(curr!=NULL){
            
            Node*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            
        }
        
        return prev;
    }

    Node *compute(Node *head)
    {
        // your code goes here
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node* head1=head;
        head1=rev(head1);
        
        int maxi=INT_MIN;
        
        Node* curr=head1;
        Node*prev=NULL;
        
        while(curr!=NULL){
            
            if(curr->data >=maxi){
                maxi=curr->data;
                prev=curr;
                curr=curr->next;
            }
            
            else{
                Node*temp=curr;
                curr=temp->next;
                prev->next=curr;
                
                temp->next=NULL;
                delete temp;
            }
        }
        
        head1=rev(head1);
        
        return head1;
     
    }
    
};
